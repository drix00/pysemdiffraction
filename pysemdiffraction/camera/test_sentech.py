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

# Local modules.

# Project modules.
from pysemdiffraction.camera.sentech import Sentech


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


if __name__ == '__main__':  # pragma: no cover
    import nose
    nose.runmodule()
