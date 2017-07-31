"""
Functions for managing application directories
"""

import os.path
import subprocess
import logging


logger = logging.getLogger(__name__)


def get_var_directory():
    """
    Return the path of the directory used to store data generated 
    by the application
    
    If the directory does not exist, it is created
    :return: data directory path
    """
    # the directory is expected to be in /var, living alongside the application directory
    return _get_sub_directory(os.path.join(os.getcwd(), '..'), 'var')


def _get_sub_directory(parent_directory, sub_directory):
    """Get the path of any subdirectory located within the specified parent directory
    If the directory does not exist, it is created
    :param parent_directory: Path of the directory the subdirectory is located in
    :param sub_directory: Name of the subdirectory
    :return: subdirectory path
    """
    directory = os.path.join(parent_directory, sub_directory)
    # create directory if it does not exist
    if not os.path.exists(directory):
        os.makedirs(directory)
    return directory
