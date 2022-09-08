from core import *
import sys

logger = getLogger(__name__)
logger.info(f'Loading {__file__}, \
            __name__:{__name__}, \
            sys.version: {sys.version}')


def test_lambda_01():
    g = lambda x: x**2 
    logger.info(f'g(2): {g(2)}')
    logger.info(f'g(3): {g(3)}')
    