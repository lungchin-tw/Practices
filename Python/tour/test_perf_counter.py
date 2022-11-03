from core import *
import sys

logger = getLogger(__name__)
logger.info(f'Loading {__file__}, \
            __name__:{__name__}, \
            sys.version: {sys.version}')


import time



def test_per_counter():
    start = time.perf_counter()
    logger.info(f'sleeping 1 second...start:{start}')
    time.sleep(1)
    finish = time.perf_counter()
    logger.info(f'done sleeping...finish:{finish}')
    logger.info(f'spend {round(finish-start, 5)} seconds')

    
    