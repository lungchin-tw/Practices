
from core import *

logger = getLogger(__name__)
logger.setLevel(logging.DEBUG)
logger.info(f'Loading {__file__}, __name__:{__name__}')


class DemoClass:
    def __init__(self, name):
        logger.info(func_desc())
        self.name = name

    def __call__(self):
        logger.info(func_desc())
        logger.info(f'serlf.name: {self.name}')
        

def test_class_callable():
    logger.info(func_desc())
    demo = DemoClass('jacky-chen')
    demo()

    