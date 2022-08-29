
import logging, sys, random


random.seed()


def getLogger(name: str):
    logger = logging.getLogger(name)
    logger.setLevel(logging.DEBUG)
    return logger


def func_desc(instance=None) -> str:
    frame = sys._getframe(1)
    info = f'{frame.f_code.co_name}, {frame.f_code.co_filename}:{frame.f_lineno}'
    if instance is None:
        return info
    else:
        return f'{instance.__class__.__name__}:{info}'


logger = getLogger(__name__)
logger.info(f'Loading {__file__}, __name__:{__name__}')
