

from core import *
from  uuid import  uuid4
from functools import wraps
import  random, datetime


logger = getLogger(__name__)
logger.info(f'Loading {__file__}, __name__:{__name__}')

def wraplog(func):
    @wraps(func) # keep orignal func name when using multiple decorators in one function
    def wrapper(*args, **kwargs):
        start = datetime.datetime.now()
        logger.info(f'Started:{func.__qualname__}, args:{args}, kwargs:{kwargs}')
        val = func(*args, **kwargs)
        elapsed = datetime.datetime.now() - start
        logger.info(f'Ended:{func.__qualname__}, Elapsed:{elapsed}')
        return val
    return wrapper


def logfuncdesc(func):
    @wraps(func) # keep orignal func name when using multiple decorators in one function
    def wrapper(*args, **kwargs):
        logger.info(f'@logfuncdesc: {func_desc()}')
        return func(*args, **kwargs)
    return wrapper


@wraplog
def hello(uuid, field='UUID'):
    logger.info(
        {
            "Desc": func_desc(),
            field: uuid,
        }
    )

@wraplog
def add(x, y: int) -> int:
    logger.info(
        {
            "Desc": func_desc(),
            "x": x,
            "y": y,
        }
    )
    return x + y

@wraplog
def print_func_special_attrs(func):
    logger.info(f'type: {type(func)}')
    logger.info(f'__doc__: {func.__doc__}')
    logger.info(f'__name__: {func.__name__}')
    logger.info(f'__qualname__: {func.__qualname__}')
    logger.info(f'__module__: {func.__module__}')
    logger.info(f'__defaults__: {func.__defaults__}')
    logger.info(f'__code__: {func.__code__}')
    logger.info(f'__globals__: {func.__globals__}')
    logger.info(f'__dict__: {func.__dict__}')
    logger.info(f'__closure__: {func.__closure__}')
    logger.info(f'__annotations__: {func.__annotations__}')
    logger.info(f'__kwdefaults__: {func.__kwdefaults__}')
    if func.__class__ is not None:
        logger.info(f'__class__: {func.__class__}')


class DemoClass:
    @wraplog
    def demo_decorated_method(self, msg:str):
        logger.info(
            {
                "Desc": func_desc(),
                "Message": msg,
            }
        )

    @logfuncdesc
    def demo_wrap_log_func_desc_method(self):
        logger.info(func_desc())


@wraplog
def test_func_decorator():
    range = 100
    logger.info({"Desc": func_desc()})

    logger.info(f'hello.__qualname__:{hello.__qualname__}')
    hello(uuid4())

    logger.info(f'add.__qualname__:{add.__qualname__}')
    logger.info({
        "Result": add(random.randrange(range), random.randrange(range)),
    })

    logger.info(f'DemoClass.demo_decorated_method.__qualname__:{DemoClass.demo_decorated_method.__qualname__}')
    DemoClass().demo_decorated_method('Hi, DemoClass')
    logger.info(f'DemoClass.demo_decorated_method.__qualname__:{DemoClass.demo_wrap_log_func_desc_method.__qualname__}')
    DemoClass().demo_wrap_log_func_desc_method()

    logger.info(f'print_func_special_attrs.__qualname__:{print_func_special_attrs.__qualname__}')
    print_func_special_attrs(DemoClass.demo_decorated_method)



@wraplog
def test_print_func_special_attrs():
    logger.info(f'print_func_special_attrs.__qualname__:{print_func_special_attrs.__qualname__}')
    print_func_special_attrs(DemoClass.demo_decorated_method)