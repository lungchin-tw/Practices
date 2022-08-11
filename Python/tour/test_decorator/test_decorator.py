

from core import *
from  uuid import  uuid4
import  random, datetime

logger = getLogger(__name__)
logger.info(f'Loading {__file__}, __name__:{__name__}')

def wraplog(func):
    def wrapper(*args, **kwargs):
        start = datetime.datetime.now()
        logger.info(f'Started:{func}, args:{args}, kwargs:{kwargs}')
        val = func(*args, **kwargs)
        elapsed = datetime.datetime.now() - start
        logger.info(f'Ended:{func}, Elapsed:{elapsed}')
        return val
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

class DemoClass:
    @wraplog
    def demo_decorated_method(self, msg:str):
        logger.info(
            {
                "Desc": func_desc(),
                "Message": msg,
            }
        )


@wraplog
def test_decorator():
    range = 100
    logger.info({"Desc": func_desc()})

    hello(uuid4())

    logger.info({
        "Result": add(random.randrange(range), random.randrange(range)),
    })

    DemoClass().demo_decorated_method('Hi, DemoClass')

