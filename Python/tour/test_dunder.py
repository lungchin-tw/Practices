
import logging
import sys

logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)
logger.info(f'Loading {__file__}, \
            __name__:{__name__}, \
            sys.version: {sys.version}')


from core import *


class DemoClass(object):
    def __init__(self, msg):
        self.message = msg

    def __repr__(self) -> str:
        return f'{self.__class__.__name__}: {self.message}'


def test_dunder():
    a = DemoClass('DemoClass Dunder Test')
    logger.info(a)
    
