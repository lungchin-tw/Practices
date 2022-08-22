
import logging
import sys

logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)
logger.info(f'Loading {__file__}, \
            __name__:{__name__}, \
            sys.version: {sys.version}')

def test_dict():
    kv = {}
    code = 100
    key = f'{code}'
    logger.info(f'Before: Dict={kv}')
    if key not in kv:
        kv[key] = 1

    kv[key] = kv[key] + 1
    logger.info(f'After: Dict={kv}')
    