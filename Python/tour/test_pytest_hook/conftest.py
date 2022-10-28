

import logging
from core import getLogger, func_desc

logger = getLogger(__name__)
logger.setLevel(logging.DEBUG)
logger.info(f'Loading {__file__}, __name__:{__name__}')


def pytest_configure():
    logger.info(func_desc())