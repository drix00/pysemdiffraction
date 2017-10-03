#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
.. py:currentmodule:: pysemdiffraction.camera.sentech.standard
   :synopsis: Python wrapper on the Sentech camera API.

.. moduleauthor:: Hendrix Demers <hendrix.demers@mail.mcgill.ca>

Python wrapper on the Sentech camera Standard SDK API.
"""

###############################################################################
# Copyright 2017 Hendrix Demers
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
###############################################################################

# Standard library modules.
import platform
import logging
from struct import Struct
from enum import Enum

# Third party modules.
from cffi import FFI
import six

# Local modules.

# Project modules.
from pysemdiffraction import get_current_module_path

# Globals and constants variables.


class ColorArray(Enum):
    STCAM_COLOR_ARRAY_NONE = 0x0000
    STCAM_COLOR_ARRAY_MONO = 0x0001
    STCAM_COLOR_ARRAY_RGGB = 0x0002
    STCAM_COLOR_ARRAY_GRBG = 0x0003
    STCAM_COLOR_ARRAY_GBRG = 0x0004
    STCAM_COLOR_ARRAY_BGGR = 0x0005


class UsbPid(Enum):
    STCAM_USBPID_STC_B33USB = 0x0705
    STCAM_USBPID_STC_C33USB = 0x0305
    STCAM_USBPID_STC_B83USB = 0x0805
    STCAM_USBPID_STC_C83USB = 0x0605
    STCAM_USBPID_STC_TB33USB = 0x0906
    STCAM_USBPID_STC_TC33USB = 0x1006
    STCAM_USBPID_STC_TB83USB = 0x1106
    STCAM_USBPID_STC_TC83USB = 0x1206
    STCAM_USBPID_STC_TB133USB = 0x0109
    STCAM_USBPID_STC_TC133USB = 0x0209
    STCAM_USBPID_STC_TB152USB = 0x1306
    STCAM_USBPID_STC_TC152USB = 0x1406
    STCAM_USBPID_STC_TB202USB = 0x1506
    STCAM_USBPID_STC_TC202USB = 0x1606
    STCAM_USBPID_STC_MB33USB = 0x0110
    STCAM_USBPID_STC_MC33USB = 0x0210
    STCAM_USBPID_STC_MB83USB = 0x0310
    STCAM_USBPID_STC_MC83USB = 0x0410
    STCAM_USBPID_STC_MB133USB = 0x0510
    STCAM_USBPID_STC_MC133USB = 0x0610
    STCAM_USBPID_STC_MB152USB = 0x0710
    STCAM_USBPID_STC_MC152USB = 0x0810
    STCAM_USBPID_STC_MB202USB = 0x0910
    STCAM_USBPID_STC_MC202USB = 0x1010
    STCAM_USBPID_APBWVUSB_LED = 0x0509
    STCAM_USBPID_APCWVUSB_LED = 0x0609
    STCAM_USBPID_STC_MBA5MUSB3 = 0x0111
    STCAM_USBPID_STC_MCA5MUSB3 = 0x0211
    STCAM_USBPID_STC_MBE132U3V = 0x0112
    STCAM_USBPID_STC_MCE132U3V = 0x0212
    STCAM_USBPID_STC_MBCM401U3V = 0x0113
    STCAM_USBPID_STC_MCCM401U3V = 0x0213
    STCAM_USBPID_STC_MBCM200U3V = 0x0313
    STCAM_USBPID_STC_MCCM200U3V = 0x0413
    STCAM_USBPID_STC_MBCM33U3V = 0x0513
    STCAM_USBPID_STC_MCCM33U3V = 0x0613
    STCAM_USBPID_STC_MBS241U3V = 0x0713
    STCAM_USBPID_STC_MCS241U3V = 0x0813
    STCAM_USBPID_STC_MBE132U3V_IR = 0x0114
    STCAM_USBPID_STC_RHB33U3V = 0x0115
    STCAM_USBPID_STC_RHC33U3V = 0x0215
    STCAM_USBPID_STC_MBS510U3V = 0x0315
    STCAM_USBPID_STC_MCS510U3V = 0x0415
    STCAM_USBPID_STC_MBS322U3V = 0x0515
    STCAM_USBPID_STC_MCS322U3V = 0x0615


class CameraFunction(Enum):
    STCAM_CAMERA_FUNCTION_VGA90FPS = 0
    STCAM_CAMERA_FUNCTION_STARTSTOP = 1
    STCAM_CAMERA_FUNCTION_EXPOSURE_MODE_TRIGGER_CONTROLLED = 1
    STCAM_CAMERA_FUNCTION_MEMORY = 2
    STCAM_CAMERA_FUNCTION_IO_CHANGE_DIRECTION = 4
    STCAM_CAMERA_FUNCTION_LED = 5
    STCAM_CAMERA_FUNCTION_DISABLE_DIP_SW = 7
    STCAM_CAMERA_FUNCTION_10BIT = 8
    STCAM_CAMERA_FUNCTION_12BIT = 15
    STCAM_CAMERA_FUNCTION_CDS_GAIN_TYPE = 16
    STCAM_CAMERA_FUNCTION_PHOTOCOUPLER = 17
    STCAM_CAMERA_FUNCTION_TRIGGER_OVERLAP_OFF_PREVIOUS_FRAME = 18
    STCAM_CAMERA_FUNCTION_TRIGGER_MASK = 18
    STCAM_CAMERA_FUNCTION_V_BLANK_FOR_FPS = 21
    STCAM_CAMERA_FUNCTION_MIRROR_HORIZONTAL = 22
    STCAM_CAMERA_FUNCTION_MIRROR_VERTICAL = 23
    STCAM_CAMERA_FUNCTION_AWB = 24
    STCAM_CAMERA_FUNCTION_AGC = 25
    STCAM_CAMERA_FUNCTION_AE = 26
    STCAM_CAMERA_FUNCTION_IO_UNIT_US = 27
    STCAM_CAMERA_FUNCTION_SENSOR_SHUTTER_MODE_0 = 28
    STCAM_CAMERA_FUNCTION_CMOS_RESET_TYPE_ERS_GRR = 28
    STCAM_CAMERA_FUNCTION_CMOS_RESET_TYPE_0 = 28
    STCAM_CAMERA_FUNCTION_DISABLED_READOUT = 29
    STCAM_CAMERA_FUNCTION_DIGITAL_CLAMP = 55
    STCAM_CAMERA_FUNCTION_TRIGGER_VALID_OUT = 56
    STCAM_CAMERA_FUNCTION_CAMERA_GAMMA = 57
    STCAM_CAMERA_FUNCTION_STORE_CAMERA_SETTING = 58
    STCAM_CAMERA_FUNCTION_DEFECT_PIXEL_CORRECTION = 59
    STCAM_CAMERA_FUNCTION_DISABLE_MEMORY_TYPE_SELECTION = 60
    STCAM_CAMERA_FUNCTION_H_BINNING_SUM = 61
    STCAM_CAMERA_FUNCTION_BINNING_COLUMN_SUM = 61
    STCAM_CAMERA_FUNCTION_DISABLE_EXPOSURE_START_WAIT_HD = 62
    STCAM_CAMERA_FUNCTION_DISABLE_EXPOSURE_START_WAIT_READ_OUT = 63
    STCAM_CAMERA_FUNCTION_IO_RESET_SW_DISABLED = 68
    STCAM_CAMERA_FUNCTION_DISABLE_PULSE_WIDTH_EXPOSURE = 69
    STCAM_CAMERA_FUNCTION_EXPOSURE_MODE_TRIGGER_WIDTH_DISABLE = 69
    STCAM_CAMERA_FUNCTION_CMOS_RESET_TYPE_1 = 72
    STCAM_CAMERA_FUNCTION_SENSOR_SHUTTER_MODE_1 = 72
    STCAM_CAMERA_FUNCTION_V_BINNING_SUM = 131
    STCAM_CAMERA_FUNCTION_TRIGGER = 256
    STCAM_CAMERA_FUNCTION_DIGITAL_GAIN = 257
    STCAM_CAMERA_FUNCTION_VARIABLE_PARTIAL = 258
    STCAM_CAMERA_FUNCTION_BINNING_PARTIAL = 259
    STCAM_CAMERA_FUNCTION_IO = 260
    STCAM_CAMERA_FUNCTION_RESET_FRAME_COUNTER = 261
    STCAM_CAMERA_FUNCTION_ANALOG_BLACK_LEVEL = 0x00050006
    STCAM_CAMERA_FUNCTION_DISABLED_ANALOG_GAIN = 0x00090004
    STCAM_CAMERA_FUNCTION_AGC_GAIN_TYPE = 0x00090005
    STCAM_CAMERA_FUNCTION_DEVICE_TEMPERATURE_MAINBOARD = 0x00090009
    STCAM_CAMERA_FUNCTION_ADJUSTMENT_MODE_DIGITAL_GAIN = 0x0009000A
    STCAM_CAMERA_FUNCTION_EXPOSURE_END_TRIGGER_SOURCE = 0x0009000C
    STCAM_CAMERA_FUNCTION_STARTSTOP_TRIGGER_SOURCE = 0x0009000C
    STCAM_CAMERA_FUNCTION_FRAME_BURST_START = 0x0009000E
    STCAM_CAMERA_FUNCTION_TRANSFER_END_OUT = 0x0009000F
    STCAM_CAMERA_FUNCTION_LINE_DEBOUNCE_TIME = 0x000A0009
    STCAM_CAMERA_FUNCTION_EVENT = 0x000A000B
    STCAM_CAMERA_FUNCTION_GENICAM_IO = 0x000A000C


class ScanMode(Enum):
    STCAM_SCAN_MODE_NORMAL = 0x0000
    STCAM_SCAN_MODE_PARTIAL_2 = 0x0001
    STCAM_SCAN_MODE_PARTIAL_4 = 0x0002
    STCAM_SCAN_MODE_PARTIAL_1 = 0x0004
    STCAM_SCAN_MODE_VARIABLE_PARTIAL = 0x0008
    STCAM_SCAN_MODE_BINNING = 0x0010
    STCAM_SCAN_MODE_BINNING_PARTIAL_1 = 0x0020
    STCAM_SCAN_MODE_BINNING_PARTIAL_2 = 0x0040
    STCAM_SCAN_MODE_BINNING_PARTIAL_4 = 0x0080
    STCAM_SCAN_MODE_BINNING_VARIABLE_PARTIAL = 0x0100
    STCAM_SCAN_MODE_ROI = 0x8000
    STCAM_SCAN_MODE_AOI = 0x8000


class Sentech(object):

    def __init__(self):
        self.ffi = FFI()
        self.ffi.set_unicode(True)

        self.library_handler = None
        self.camera_handle = None

        self.is_transferring_image = False
        self.is_inside_callback_function = False

        self.init_api()

    def init_api(self):
        include_file_path = self.get_include_file_path()
        with open(include_file_path, 'r') as include_file:
            logging.info("Reading the include file")
            self.ffi.cdef(include_file.read())

        dll_file_path = self.get_dll_file_path()
        self.library_handler = self.ffi.dlopen(dll_file_path)

    def get_dll_file_path(self):
        if platform.architecture()[0] == '64bit':
            dll_file_path = get_current_module_path(__file__, "../../../lib/camera/x64/StCamD.dll")
            logging.debug("64 bit platform found")
        elif platform.architecture()[0] == '32bit':
            dll_file_path = get_current_module_path(__file__, "../../../lib/camera/x86/StCamD.dll")
            logging.debug("32 bit platform found")
        else:
            message = "Cannot determine platform architecture: 32-bit or 64-bit."
            logging.error(message)
            raise RuntimeError(message)

        logging.debug("dll_file_path: {:s}".format(dll_file_path))
        return dll_file_path

    def get_include_file_path(self):
        include_file_path = get_current_module_path(__file__, "../../../include/camera/StCamD_stripped.h")
        logging.info("include_file_path: {:s}".format(include_file_path))
        return include_file_path

    def get_api_version(self):
        if self.library_handler is None:
            logging.info("No library handle found, try to initialize the api")
            self.init_api()

        file_version_ms = self.ffi.new("PDWORD", 0)
        file_version_ls = self.ffi.new("PDWORD", 0)
        _product_version_ms = self.ffi.new("PDWORD", 0)
        _product_version_ls = self.ffi.new("PDWORD", 0)

        status = self.library_handler.StTrg_GetDllVersion(file_version_ms, file_version_ls, _product_version_ms,
                                                          _product_version_ls)

        if not status:
            logging.error("Cannot get the dll version")

        s = Struct("4B")
        logging.debug(s.unpack(self.ffi.buffer(file_version_ms, 4)))
        minor, _, major, _ = s.unpack(self.ffi.buffer(file_version_ms, 4))
        build = file_version_ls[0]
        logging.debug(file_version_ls[0])

        api_version = (major, minor, 0, build)

        return api_version

    def get_api_file_version(self):
        if self.library_handler is None:
            logging.info("No library handle found, try to initialize the api")
            self.init_api()

        _file_version_ms = self.ffi.new("PDWORD", 0)
        _file_version_ls = self.ffi.new("PDWORD", 0)
        product_version_ms = self.ffi.new("PDWORD", 0)
        product_version_ls = self.ffi.new("PDWORD", 0)

        status = self.library_handler.StTrg_GetDllVersion(_file_version_ms, _file_version_ls, product_version_ms,
                                                          product_version_ls)

        if not status:
            logging.error("Cannot get the ddl version")

        s = Struct("4B")
        logging.debug(s.unpack(self.ffi.buffer(product_version_ms, 4)))
        minor, _, major, _ = s.unpack(self.ffi.buffer(product_version_ms, 4))
        build = product_version_ls[0]
        logging.debug(product_version_ls[0])

        api_file_version = (major, minor, 0, build)

        return api_file_version

    def get_camera_version(self):
        self._find_camera()

        usb_vendor_id = self.ffi.new("PWORD", 0)
        usb_product_id = self.ffi.new("PWORD", 0)
        fpga_version = self.ffi.new("PWORD", 0)
        firmwre_version = self.ffi.new("PWORD", 0)

        status = self.library_handler.StTrg_GetCameraVersion(self.camera_handle, usb_vendor_id, usb_product_id,
                                                             fpga_version, firmwre_version)

        if not status:
            logging.error("Cannot get the ddl version")

        logging.info(usb_vendor_id[0])
        logging.info(usb_product_id[0])
        logging.info(fpga_version[0])
        logging.info(firmwre_version[0])

        return usb_vendor_id[0], usb_product_id[0], fpga_version[0], firmwre_version[0]

    def open_camera(self):
        if self.library_handler is None:
            logging.info("No library handle found, try to initialize the api")
            self.init_api()

        self.camera_handle = self.library_handler.StTrg_Open()

        if self.camera_handle_value == -1:
            logging.error("Cannot open the camera")
            logging.info(self.camera_handle)

    def close_camera(self):
        if self.library_handler is None:
            logging.info("No library handle found, the camera is not open")
            return

        if self.camera_handle is None or self.camera_handle_value == -1:
            logging.info("No camera handle found, the camera is not open")
            self.camera_handle = None
            return

        if self.is_inside_callback_function:
            logging.warning("Inside the callback function, cannot close the camera.")
            return

        self.library_handler.StTrg_Close(self.camera_handle)

        self.camera_handle = None

    def get_product_name(self):
        self._find_camera()

        product_name = ""

#        product_name_buffer = self.ffi.new("PSTR[]", 256)
#        buffer_size = len(product_name_buffer)
#        status = self.library_handler.StTrg_GetProductNameA(self.camera_handle, product_name_buffer, buffer_size)
#        if not status:
#            logging.error("Cannot get the GetProductNameA")
#        logging.info(product_name_buffer[0])
#        logging.info(product_name_buffer)
#        #logging.info(self.ffi.string(product_name_buffer))
#        logging.info(buffer_size)

        product_name_buffer = self.ffi.new("PWSTR")
        buffer_size = 256
        status = self.library_handler.StTrg_GetProductNameW(self.camera_handle, product_name_buffer, buffer_size)
        if not status:
            logging.error("Cannot get the GetProductNameW")
        logging.info(product_name_buffer[0])
        logging.info(self.ffi.string(product_name_buffer))
        logging.info(buffer_size)

        product_name = self.ffi.string(product_name_buffer)

        return product_name

    def has_function(self, camera_function_id):
        self._find_camera()

        function_availability = self.ffi.new("BOOL*", False)
        status = self.library_handler.StTrg_HasFunction(self.camera_handle, camera_function_id, function_availability)
        if not status:
            logging.error("Cannot get the GetProductNameW")
        logging.info(camera_function_id)
        logging.info(function_availability[0])

        return bool(function_availability[0])

    def _find_camera(self):
        if self.library_handler is None:
            logging.info("No library handle found, try to initialize the api")
            self.init_api()
        if self.library_handler is not None and (self.camera_handle is None or self.camera_handle_value == -1):
            logging.info("No camera handle found, try to open the camera")
            self.open_camera()

    def check_all_functions(self):
        camera_function_ids = [0, 1, 2, 4, 5, 7, 8, 15, 17, 18, 21, 22, 23, 24, 25, 26, 27, 28, 29, 55, 56, 57, 58, 59,
                               60, 61, 62, 63, 68, 69, 72, 131, 256, 257, 258, 259, 260, 261,
                               0x00050006, 0x00090004, 0x00090005, 0x00090009, 0x0009000A, 0x0009000C, 0x0009000F,
                               0x000A000C]

        function_availabilities = {}

        for camera_function_id in camera_function_ids:
            function_availability = self.has_function(camera_function_id)
            function_availabilities[camera_function_id] = function_availability

        return function_availabilities

    def print_available_functions(self):
        function_availabilities = self.check_all_functions()

        for key, value in function_availabilities.items():
            if value:
                print("{:d} -> {:s}".format(key, str(value)))

    def get_color_array(self):
        self._find_camera()

        color_array = self.ffi.new("PWORD", 0)
        status = self.library_handler.StTrg_GetColorArray(self.camera_handle, color_array)

        if not status:
            logging.error("Cannot get the color array")

        logging.info(color_array[0])

        return ColorArray(color_array[0])

    def get_camera_user_id(self):
        self._find_camera()

        camera_id = self.ffi.new("PDWORD", 0)
        if six.PY3:
            camera_name_buffer = self.ffi.new("PWSTR")
            buffer_size = 250
            status = self.library_handler.StTrg_ReadCameraUserIDW(self.camera_handle, camera_id, camera_name_buffer, buffer_size)
        elif six.PY2:
            #camera_name_buffer = self.ffi.new("PSTR")
            camera_name_buffer = self.ffi.new("PWSTR")
            buffer_size = 250
            #status = self.library_handler.StTrg_ReadCameraUserIDA(self.camera_handle, camera_id, camera_name_buffer, buffer_size)
            status = self.library_handler.StTrg_ReadCameraUserIDW(self.camera_handle, camera_id, camera_name_buffer, buffer_size)
        if not status:
            logging.error("Cannot get the camera user ID")

        logging.info(camera_id[0])
        logging.info(camera_name_buffer[0])
        logging.info(self.ffi.string(camera_name_buffer))
        logging.info(buffer_size)

        camera_name = self.ffi.string(camera_name_buffer)

        return camera_id[0], camera_name

    def is_prohibited_call_timing(self):
        prohibited = self.is_transferring_image or self.is_inside_callback_function
        return prohibited

    def read_setting_file(self, setting_file_path):
        if self.is_prohibited_call_timing():
            logging.warning("Prohibited function call timing, read_setting_file.")
            return

        self._find_camera()

        if six.PY3:
            setting_file_path_buffer = self.ffi.new("PCWSTR", setting_file_path[0])
            status = self.library_handler.StTrg_ReadSettingFileW(self.camera_handle, setting_file_path_buffer)
        elif six.PY2:
            setting_file_path_buffer = self.ffi.new("PCSTR", setting_file_path[0])
            status = self.library_handler.StTrg_ReadSettingFileA(self.camera_handle, setting_file_path_buffer)
        if not status:
            logging.error("Cannot get the read setting file: {:s}".format(setting_file_path))
        logging.info(setting_file_path_buffer[0])
        logging.info(self.ffi.string(setting_file_path_buffer))

    def write_setting_file(self, setting_file_path):
        if self.is_prohibited_call_timing():
            logging.warning("Prohibited function call timing, write_setting_file.")
            return

        self._find_camera()

        if six.PY3:
            setting_file_path_buffer = self.ffi.new("PCWSTR", setting_file_path[0])
            status = self.library_handler.StTrg_WriteSettingFileW(self.camera_handle, setting_file_path_buffer)
        elif six.PY2:
            setting_file_path_buffer = self.ffi.new("PCSTR", setting_file_path[0])
            status = self.library_handler.StTrg_WriteSettingFileA(self.camera_handle, setting_file_path_buffer)
        if not status:
            logging.error("Cannot get the write setting file: {:s}".format(setting_file_path))

        logging.info(setting_file_path_buffer[0])
        logging.info(self.ffi.string(setting_file_path_buffer))

    def get_available_scan_mode(self):
        self._find_camera()

        enable_scan_mode = self.ffi.new("PWORD", 0)
        status = self.library_handler.StTrg_GetEnableScanMode(self.camera_handle, enable_scan_mode)
        if not status:
            logging.error("Cannot get the available scan mode")

        logging.info(enable_scan_mode[0])

        return hex(enable_scan_mode[0])

    def get_scan_mode(self):
        self._find_camera()

        scan_mode = self.ffi.new("PWORD", 0)
        offset_x = self.ffi.new("PDWORD", 0)
        offset_y = self.ffi.new("PDWORD", 0)
        width = self.ffi.new("PDWORD", 0)
        height = self.ffi.new("PDWORD", 0)
        status = self.library_handler.StTrg_GetScanMode(self.camera_handle, scan_mode, offset_x, offset_y, width, height)
        if not status:
            logging.error("Cannot get the scan mode")

        logging.info(scan_mode[0])
        logging.info(offset_x[0])
        logging.info(offset_y[0])
        logging.info(width[0])
        logging.info(height[0])

        return ScanMode(scan_mode[0]), offset_x[0], offset_y[0], width[0], height[0]

    def set_scan_mode(self, scan_mode, offset_x, offset_y, width, height):
        if self.is_prohibited_call_timing():
            logging.warning("Prohibited function call timing, set_scan_mode.")
            return

        self._find_camera()

        status = self.library_handler.StTrg_SetScanMode(self.camera_handle, scan_mode.value, offset_x, offset_y, width, height)
        if not status:
            logging.error("Cannot set the scan mode")

    @property
    def camera_handle_value(self):
        if self.camera_handle is None:
            return None
        else:
            camera_handle_value = int(self.ffi.cast('int', self.camera_handle))
            return camera_handle_value
