"""
Logging configuration
"""

import os.path
import logging
import logging.config
import logging.handlers


def setup(log_to_console=True, log_to_file=True, file_directory='', file_logging_level="INFO", configure_root=False):
    """Setup python logging module with defined handlers

    :param log_to_console: Log output to console (default True)
    :param log_to_file: Log output to specified file (default True)
    :param file_directory: Directory to place the logs folder (default is working directory)
    :param file_logging_level: Lowest logging level to include in file output (default "INFO")
    :param configure_root: Apply logging settings to root logger if True. False by default.
    """

    handlers = {}  # dictionary to store all handler configurations
    active_handlers = []  # list of handlers to apply to the logger

    if log_to_console:
        handlers["console"] = {
                "class": "logging.StreamHandler",
                "formatter": "tabbed",
                "level": "DEBUG",
                "stream": "ext://sys.stdout"
            }

        active_handlers.append("console")

    if log_to_file:
        log_directory = os.path.join(file_directory, 'logs')

        # create logs directory if it does not exist
        if not os.path.exists(log_directory):
            os.makedirs(log_directory)

        log_name = os.path.join(log_directory, 'bubble.log')

        handlers["file"] = {
                "class": "logging.handlers.TimedRotatingFileHandler",
                "formatter": "tabbed",
                "level": file_logging_level,
                "filename": log_name,
                "when": "midnight",
                "backupCount": 30
            }

        active_handlers.append("file")

    log_config = {
        "version": 1,
        "disable_existing_loggers": False,
        "formatters": {
            "tabbed": {
                "format": "%(levelname)s    %(asctime)s.%(msecs)03d    %(name)s    %(message)s",
                "datefmt": "%Y-%m-%d %H:%M:%S"
            }
        },
        "handlers": handlers
    }

    if configure_root:
        log_config["root"] = {
            "level": "DEBUG",
            "handlers": active_handlers,
        }
    else:
        log_config["loggers"] = {
            "bubble": {
                "level": "DEBUG",
                "handlers": active_handlers,
            },
        }

    logging.config.dictConfig(log_config)
