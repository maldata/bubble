import os
import sys
import time
import signal
import logging
import threading
import traceback

from pydispatch import dispatcher

from .utilities import log, directory
from .version import VERSION


def main():
    # get directory to place logs in
    var_dir = directory.get_var_directory()

    # setup logging with default configuration
    log.setup(file_directory=var_dir)
    logger = logging.getLogger(__name__)
    logger.info("Starting application v{0}".format(VERSION))
    
    # hook into SIGINT signal to shutdown the application when commanded
    def sig_int_handler(signal, frame):
        logger.info("SIGINT received - stopping application")
        manager.stop()
        app_state.running = False

    signal.signal(signal.SIGINT, sig_int_handler)

    # terminate the application when unhandled exceptions are thrown
    def exception_hook(etype, value, tb):
        logger.fatal("Uncaught exception\n%s", ''.join(traceback.format_exception(etype, value, tb)))
        logger.info("Terminating application")
        try:
            def hard_exit():
                logger.error("Failed to shutdown gracefully in time, terminating process")
                os._exit(os.EX_SOFTWARE)
                
            # in case something hangs on shutdown, take the ugly approach after 5 seconds
            hard_exit = threading.Timer(5, hard_exit)
            hard_exit.daemon = True
            hard_exit.start()
            
            sys.exit(1)

        except Exception:
            logger.exception("Exception occurred during shutdown, terminating process")
            os._exit(os.EX_SOFTWARE)

    sys.excepthook = exception_hook

    logger.info("Application has started")
    logger.info("Application has shutdown")
    
