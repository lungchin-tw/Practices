
from core import *
from functools import wraps

logger = getLogger(__name__)
logger.info(f'Loading {__file__}, __name__:{__name__}')

def deco_with_param(expr):
    def show_func_sign(func):
        @wraps(func) # to keep the original signature
        def wrapper(*args, **kwargs):
            logger.info(f'Started:{func.__qualname__}, args:{args}, kwargs:{kwargs}')
            val = func(*args, **kwargs)
            return f'{val}, {expr}!!!'
        return wrapper
    return show_func_sign


@deco_with_param('jacky-chen')
def hello():
    return 'Hello'
    

def test_decorator_with_param():
    logger.info(func_desc())
    logger.info(f'hello.__qualname__: {hello.__qualname__}, hello():{hello()}')
