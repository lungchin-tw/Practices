
import logging
import sys

logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)
logger.info(f'Loading {__file__}, \
            __name__:{__name__}, \
            sys.version: {sys.version}')

from core import *

kv = {}

logger.info(f'{func_desc()}: dir(): {dir()}')

def test_dir_1():
    logger.info(f'{func_desc()}: dir(): {dir()}')
    logger.info(f'{func_desc()}: dir(kv): {dir(kv)}')
    
logger.info(f'finally, dir(): {dir()}')
