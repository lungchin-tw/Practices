import logging
logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)

logger.info(f'Loading {__file__}, __name__:{__name__}')

from core import func_desc


def test_decorator():
    logger.info({"Desc": func_desc()})
