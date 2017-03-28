#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
.. py:currentmodule:: pysemdiffraction.__init__
.. moduleauthor:: Hendrix Demers <hendrix.demers@mail.mcgill.ca>

"""

# Standard library modules.
import os.path

# Third party modules.

# Local modules.

# Globals and constants variables.
__author__ = """Hendrix Demers"""
__email__ = 'hendrix.demers@mail.mcgill.ca'
__version__ = '0.1.0'


def get_current_module_path(module_path, relative_path=""):
    """
    Extract the current module path and combine it with the relative path and return it.

    :param str module_path: Pass the `__FILE__` python keyword for this parameter
    :param str relative_path: The relative path to combine with the module path
    :return: The path obtained when combine the module path and relative path
    :rtype: str
    """
    base_path = os.path.dirname(module_path)
    file_path = os.path.join(base_path, relative_path)
    file_path = os.path.normpath(file_path)

    return file_path
