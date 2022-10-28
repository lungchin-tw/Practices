import logging
from core import getLogger, func_desc

logger = getLogger(__name__)
logger.setLevel(logging.DEBUG)
logger.info(f'Loading {__file__}, __name__:{__name__}')


def test_pytest_hook():
    logger.info(func_desc())