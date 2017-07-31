"""
This script launches the application, which lives entirely within
the bubble package.
"""

import os
import sys
import argparse

# update working directory to the script's directory
absolute_path = os.path.abspath(sys.argv[0])
script_directory = os.path.dirname(absolute_path)
os.chdir(script_directory)

# import app only after the working directory has been updated
import bubble.bubbleapp as app

# launch
app.main()
