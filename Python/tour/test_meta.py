
import logging
import sys

logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)
logger.info(f'Loading {__file__}, \
            __name__:{__name__}, \
            sys.version: {sys.version}')

from core import *


class Meta(type):
    def __new__(self, class_name, bases, attrs):
        logger.info(func_desc())
        logger.info(f'Self: {self}')
        logger.info(f'ClassName: {class_name}')
        logger.info(f'Bases: {bases}')
        logger.info(f'Attrs: {attrs}')
        return type(class_name, bases, attrs)
    

class DemoClass(object,metaclass=Meta):
    x = 1
    y = 2
    
    def hello(self):
        pass