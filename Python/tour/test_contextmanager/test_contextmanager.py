
from core import *
import sys

logger = getLogger(__name__)
logger.info(f'Loading {__file__}, \
            __name__:{__name__}, \
            sys.version: {sys.version}')


from datetime import datetime
from contextlib import contextmanager


@contextmanager
def filemgr(filename, method):
    logger.info(func_desc())
    f = open(filename, method)
    logger.info(func_desc())
    yield f
    logger.info(func_desc())
    f.close()
    logger.info(func_desc())


def test_contextmanager():
    logger.info(func_desc())
    with filemgr('nowith.log', 'a') as f:
        logger.info(func_desc())
        f.write(f'{datetime.now()}, {func_desc()}\n')
        logger.info(func_desc())


