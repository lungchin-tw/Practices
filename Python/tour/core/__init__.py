
import logging, sys, random


random.seed()


def getLogger(name: str):
    logger = logging.getLogger(name)
    logger.setLevel(logging.DEBUG)
    return logger


def func_desc(cls=None) -> str:
    frame = sys._getframe(1)
    if cls is None:
        return f'{frame.f_code.co_name}, {frame.f_code.co_filename}:{frame.f_lineno}'
    else:
        return f'{cls}:{frame.f_code.co_name}, {frame.f_code.co_filename}:{frame.f_lineno}'


logger = getLogger(__name__)
logger.info(f'Loading {__file__}, __name__:{__name__}')
