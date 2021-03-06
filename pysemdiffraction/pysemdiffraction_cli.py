#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
.. py:currentmodule:: pysemdiffraction
   :synopsis: Python scripts to acquire and analyze SEM diffraction pattern

.. moduleauthor:: Hendrix Demers <hendrix.demers@mail.mcgill.ca>

Python scripts to acquire and analyze SEM diffraction pattern
"""

###############################################################################
# Copyright ${year} Hendrix Demers
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
import time

# Project modules.
from pysemdiffraction.camera.sentech.trigger import Sentech

# Third party modules.
# Local modules.

# Globals and constants variables.

if __name__ == "__main__":  # pragma: no cover
    # logging.getLogger().setLevel(logging.INFO)
    sentach_api = Sentech()

    # sentech_api.init_api()
    print(sentach_api.get_api_version())
    print(sentach_api.get_api_file_version())

    sentach_api.open_camera()
    usb_vendor_id, usb_product_id, fpga_version, firmware_version = sentach_api.get_camera_version()
    print(hex(usb_vendor_id))
    print(hex(usb_product_id))
    print(fpga_version)
    print(firmware_version)
    print(hex(fpga_version))
    print(hex(firmware_version))

    print(sentach_api.get_product_name())

    function_availabilities = sentach_api.check_all_functions()

    for key, value in function_availabilities.items():
        print("{:d} -> {:s}".format(key, str(value)))

    sentach_api.print_available_functions()

    print(sentach_api.get_color_array())
    print(sentach_api.get_camera_user_id())
    time.sleep(1)
    print(sentach_api.get_available_scan_mode())
    time.sleep(1)
    # print(sentech_api.get_scan_mode())

    filename = "test_write_setting.cfg"
    # sentech_api.write_setting_file(filename)

    time.sleep(1)
    sentach_api.close_camera()
    time.sleep(2)

    print("End of the script!")
