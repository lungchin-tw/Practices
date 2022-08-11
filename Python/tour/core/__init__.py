
import logging, sys
logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)

logger.info(f'Loading {__file__}, __name__:{__name__}')


def func_desc(cls=None) -> str:
    frame = sys._getframe(1)
    if cls is None:
        return f'{frame.f_code.co_name}, {frame.f_code.co_filename}:{frame.f_lineno}'
    else:
        return f'{cls}:{frame.f_code.co_name}, {frame.f_code.co_filename}:{frame.f_lineno}'
