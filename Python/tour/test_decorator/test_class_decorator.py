
from core import *

logger = getLogger(__name__)
logger.setLevel(logging.DEBUG)
logger.info(f'Loading {__file__}, __name__:{__name__}')


class ClassDecorator:
    def __init__(self, func):
        logger.info(func_desc())
        self.func = func

    def __call__(self, *args, **kwargs):
        logger.info(func_desc())
        val = self.func(*args, **kwargs)
        return val.upper()
        
@ClassDecorator
def get_greeting_msg():
    return 'How you doing?'

def test_class_decorator():
    logger.info(func_desc())
    logger.info(get_greeting_msg())

    