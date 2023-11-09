
import logging
import sys

logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)
logger.info(f'\n\
Loading {__file__}\n\
__name__:{__name__}\n\
sys.version: {sys.version}')

def test_dict():
    kv = {}
    code = 100
    key = f'{code}'
    logger.info(f'Before: Dict={kv}')
    kv[key] = kv.get(key, 0) + 1
    logger.info(f'After: Dict={kv}')


def test_existence():
    kv = {'key1':'value1'}
    existence = 'key1' in kv
    logger.info(f'existence:{existence}')

    existence = 'key2' in kv
    logger.info(f'existence:{existence}')

    v1 = kv.get('key1', None)
    v2 = kv.get('key2', None)
    logger.info(f'v1: {v1}, v2: {v2}')
    
    