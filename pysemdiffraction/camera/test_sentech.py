#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
.. py:currentmodule:: pysemdiffraction.camera.test_sentech
   :synopsis: Tests for the module :py:mod:`pysemdiffraction.camera.sentech`

.. moduleauthor:: Hendrix Demers <hendrix.demers@mail.mcgill.ca>

Tests for the module :py:mod:`pysemdiffraction.camera.sentech`.
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
import unittest
import os.path

# Third party modules.
from cffi import FFI
from nose import SkipTest

# Local modules.

# Project modules.
from pysemdiffraction.camera.sentech import Sentech, ColorArray, ScanMode
from pysemdiffraction import get_current_module_path

# Globals and constants variables.

class TestSentech(unittest.TestCase):
    """
    TestCase class for the module `pysemdiffraction.camera.sentech`.
    """

    def setUp(self):
        """
        Setup method.
        """

        unittest.TestCase.setUp(self)

        self.sentach_api = Sentech()

    def tearDown(self):
        """
        Teardown method.
        """

        unittest.TestCase.tearDown(self)

    def testSkeleton(self):
        """
        First test to check if the testcase is working with the testing framework.
        """

        # self.fail("Test if the testcase is working.")
        self.assert_(True)

    def test_get_dll_file_path(self):
        """
        Test the method `get_dll_file_path`.
        """

        dll_file_path = self.sentach_api.get_dll_file_path()
        self.assertTrue(os.path.isfile(dll_file_path))

        # self.fail("Test if the testcase is working.")
        self.assert_(True)

    def test_get_include_file_path(self):
        """
        Test the method `get_include_file_path`.
        """

        include_file_path = self.sentach_api.get_include_file_path()
        self.assertTrue(os.path.isfile(include_file_path))

        # self.fail("Test if the testcase is working.")
        self.assert_(True)

    def test_init_api(self):
        """
        Test the method `init_api`.
        """

        self.sentach_api.ffi = FFI()
        self.sentach_api.ffi.set_unicode(True)
        self.sentach_api.library_handler = None
        self.sentach_api.camera_handle = None

        self.assertEqual(1, len(self.sentach_api.ffi._cdefsources))
        self.assertEqual(0, len(self.sentach_api.ffi._libraries))
        self.sentach_api.init_api()
        self.assertEqual(2, len(self.sentach_api.ffi._cdefsources))
        self.assertEqual(1, len(self.sentach_api.ffi._libraries))

        # self.fail("Test if the testcase is working.")
        self.assert_(True)

    def test_get_api_version(self):
        """
        Test the method `get_api_version`.
        """

        version_ref = (3, 7, 0, 3062)
        version = self.sentach_api.get_api_version()
        self.assertTupleEqual(version_ref, version)

        # self.fail("Test if the testcase is working.")
        self.assert_(True)

    def test_get_api_file_version(self):
        """
        Test the method `get_api_file_version`.
        """

        version_ref = (3, 7, 0, 3062)
        version = self.sentach_api.get_api_file_version()
        self.assertTupleEqual(version_ref, version)

        # self.fail("Test if the testcase is working.")
        self.assert_(True)

    def test_open_camera(self):
        """
        Test the method `open_camera`.
        """

        self.assertEqual(None, self.sentach_api.camera_handle_value)
        self.sentach_api.open_camera()
        self.assertEqual(-1, self.sentach_api.camera_handle_value)

        # self.fail("Test if the testcase is working.")
        self.assert_(True)

    def test_close_camera(self):
        """
        Test the method `close_camera`.
        """

        self.sentach_api.open_camera()
        self.assertEqual(-1, self.sentach_api.camera_handle_value)
        self.sentach_api.close_camera()
        self.assertEqual(None, self.sentach_api.camera_handle_value)

        # self.fail("Test if the testcase is working.")
        self.assert_(True)

    def test_get_camera_version(self):
        """
        Test the method `get_camera_version`.
        """

        usb_vendor_id_ref = 0
        usb_product_id_ref = 0
        fpga_version_ref = 0
        firmware_version_ref = 0

        usb_vendor_id, usb_product_id, fpga_version, firmware_version = self.sentach_api.get_camera_version()

        self.assertEqual(usb_vendor_id_ref, usb_vendor_id)
        self.assertEqual(usb_product_id_ref, usb_product_id)
        self.assertEqual(fpga_version_ref, fpga_version)
        self.assertEqual(firmware_version_ref, firmware_version)

        # self.fail("Test if the testcase is working.")
        self.assert_(True)

    def test_get_product_name(self):
        """
        Test the method `get_product_name`.
        """

        product_name_ref = ""

        product_name = self.sentach_api.get_product_name()

        self.assertEqual(product_name_ref, product_name)

        # self.fail("Test if the testcase is working.")
        self.assert_(True)

    def test_has_function(self):
        """
        Test the method `has_function`.
        """

        camera_function_id = 0
        function_availability = self.sentach_api.has_function(camera_function_id)
        self.assertEqual(False, function_availability)

        # self.fail("Test if the testcase is working.")
        self.assert_(True)

    def test_get_color_array(self):
        """
        Test the method `get_color_array`.
        """
        color_array_ref = ColorArray.STCAM_COLOR_ARRAY_NONE

        color_array = self.sentach_api.get_color_array()
        self.assertEqual(color_array_ref, color_array)

        # self.fail("Test if the testcase is working.")
        self.assert_(True)

    def test_get_camera_user_id(self):
        """
        Test the method `get_camera_user_id`.
        """

        camera_id_ref = 0
        camera_name_ref = ""

        camera_id, camera_name = self.sentach_api.get_camera_user_id()

        self.assertEqual(camera_id_ref, camera_id)
        self.assertEqual(camera_name_ref, camera_name)

        # self.fail("Test if the testcase is working.")
        self.assert_(True)

    def test_is_prohibited_call_timing(self):
        """
        Test the method `is_prohibited_call_timing`.
        """

        self.sentach_api.is_transferring_image = False
        self.sentach_api.is_inside_callback_function = False
        self.assertEqual(False, self.sentach_api.is_prohibited_call_timing())

        self.sentach_api.is_transferring_image = True
        self.sentach_api.is_inside_callback_function = False
        self.assertEqual(True, self.sentach_api.is_prohibited_call_timing())

        self.sentach_api.is_transferring_image = False
        self.sentach_api.is_inside_callback_function = True
        self.assertEqual(True, self.sentach_api.is_prohibited_call_timing())

        self.sentach_api.is_transferring_image = True
        self.sentach_api.is_inside_callback_function = True
        self.assertEqual(True, self.sentach_api.is_prohibited_call_timing())

        # self.fail("Test if the testcase is working.")
        self.assert_(True)

    def test_read_setting_file(self):
        """
        Test the method `read_setting_file`.
        """

        setting_file_path = get_current_module_path("__file__", "../../test_data/read_setting_file.cfg")
        if not os.path.isfile(setting_file_path):
            SkipTest

        self.sentach_api.read_setting_file(setting_file_path)

        # self.fail("Test if the testcase is working.")
        self.assert_(True)

    def test_write_setting_file(self):
        """
        Test the method `read_setting_file`.
        """

        setting_file_path_ref = get_current_module_path("__file__", "../../test_data/read_setting_file.cfg")
        if not os.path.isfile(setting_file_path_ref):
            SkipTest

        setting_file_path = get_current_module_path("__file__", "../../test_data/write_setting_file.cfg")

        self.sentach_api.write_setting_file(setting_file_path)

        # self.fail("Test if the testcase is working.")
        self.assert_(True)

    def test_get_available_scan_mode(self):
        """
        Test the method `get_available_scan_mode`.
        """
        available_scan_mode_ref = ScanMode.STCAM_SCAN_MODE_NORMAL

        available_scan_mode = self.sentach_api.get_available_scan_mode()
        self.assertEqual(available_scan_mode_ref, available_scan_mode)

        # self.fail("Test if the testcase is working.")
        self.assert_(True)

    def test_get_scan_mode(self):
        """
        Test the method `get_scan_mode`.
        """
        scan_mode_ref = ScanMode.STCAM_SCAN_MODE_NORMAL
        offset_x_ref = 0
        offset_y_ref = 0
        width_ref = 0
        height_ref = 0

        scan_mode, offset_x, offset_y, width, height = self.sentach_api.get_scan_mode()
        self.assertEqual(scan_mode_ref, scan_mode)
        self.assertEqual(offset_x_ref, offset_x)
        self.assertEqual(offset_y_ref, offset_y)
        self.assertEqual(width_ref, width)
        self.assertEqual(height_ref, height)

        # self.fail("Test if the testcase is working.")
        self.assert_(True)

    def test_set_scan_mode(self):
        """
        Test the method `set_scan_mode`.
        """
        scan_mode_ref = ScanMode.STCAM_SCAN_MODE_ROI
        offset_x_ref = 20
        offset_y_ref = 20
        width_ref = 100
        height_ref = 230

        self.sentach_api.set_scan_mode(scan_mode_ref, offset_x_ref, offset_y_ref, width_ref, height_ref)

        scan_mode_ref = ScanMode.STCAM_SCAN_MODE_NORMAL
        offset_x_ref = 0
        offset_y_ref = 0
        width_ref = 0
        height_ref = 0

        scan_mode, offset_x, offset_y, width, height = self.sentach_api.get_scan_mode()
        self.assertEqual(scan_mode_ref, scan_mode)
        self.assertEqual(offset_x_ref, offset_x)
        self.assertEqual(offset_y_ref, offset_y)
        self.assertEqual(width_ref, width)
        self.assertEqual(height_ref, height)

        # self.fail("Test if the testcase is working.")
        self.assert_(True)

if __name__ == '__main__':  # pragma: no cover
    import nose
    nose.runmodule()
