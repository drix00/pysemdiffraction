#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
.. py:currentmodule:: pysemdiffraction.camera.sentech
   :synopsis: Python wrapper on the Sentech camera API.

.. moduleauthor:: Hendrix Demers <hendrix.demers@mail.mcgill.ca>

Python wrapper on the Sentech camera API.
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

# Third party modules.
from cffi import FFI

# Local modules.

# Project modules.
from pysemdiffraction import get_current_module_path

# Globals and constants variables.


class Sentech(object):
    def __init__(self):
        self.ffi = FFI()
        self.ffi.set_unicode(True)

        self.library_handler = None
        self.camera_handle = None

    def init_api(self):
        include_file_path = self.get_include_file_path()
        with open(include_file_path, 'r') as include_file:
            logging.info("Reading the include file")
            self.ffi.cdef(include_file.read())

        dll_file_path = self.get_dll_file_path()
        self.library_handler = self.ffi.dlopen(dll_file_path)

    def get_dll_file_path(self):
        if platform.architecture()[0] == '64bit':
            dll_file_path = get_current_module_path(__file__, "../../lib/camera/x64/StTrgApi.dll")
            logging.debug("64 bit platform found")
        elif platform.architecture()[0] == '32bit':
            dll_file_path = get_current_module_path(__file__, "../../lib/camera/x86/StTrgApi.dll")
            logging.debug("32 bit platform found")
        else:
            message = "Cannot determine platform architecture: 32-bit or 64-bit."
            logging.error(message)
            raise RuntimeError(message)

        logging.debug("dll_file_path: {:s}".format(dll_file_path))
        return dll_file_path

    def get_include_file_path(self):
        include_file_path = get_current_module_path(__file__, "../../include/camera/StTrgApi_stripped.h")
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
        if self.library_handler is None:
            logging.info("No library handle found, try to initialize the api")
            self.init_api()

        if self.library_handler is not None and (self.camera_handle is None or self.camera_handle_value == -1):
            logging.info("No camera handle found, try to open the camera")
            self.open_camera()

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

        self.library_handler.StTrg_Close(self.camera_handle)

        self.camera_handle = None

    def get_product_name(self):
        if self.library_handler is None:
            logging.info("No library handle found, try to initialize the api")
            self.init_api()

        if self.library_handler is not None and (self.camera_handle is None or self.camera_handle_value == -1):
            logging.info("No camera handle found, try to open the camera")
            self.open_camera()

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
        if self.library_handler is None:
            logging.info("No library handle found, try to initialize the api")
            self.init_api()

        if self.library_handler is not None and (self.camera_handle is None or self.camera_handle_value == -1):
            logging.info("No camera handle found, try to open the camera")
            self.open_camera()

        function_availability = self.ffi.new("BOOL*", False)
        status = self.library_handler.StTrg_HasFunction(self.camera_handle, camera_function_id, function_availability)
        if not status:
            logging.error("Cannot get the GetProductNameW")
        logging.info(camera_function_id)
        logging.info(function_availability[0])

        return bool(function_availability[0])

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

    @property
    def camera_handle_value(self):
        if self.camera_handle is None:
            return None
        else:
            camera_handle_value = int(self.ffi.cast('int', self.camera_handle))
            return camera_handle_value
