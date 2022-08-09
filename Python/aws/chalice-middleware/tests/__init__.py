
import logging
logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)
logger.info(f'Loading: {__file__}, __name__:{__name__}')


from pytest import fixture
from chalice.test import Client
from chalicelib.core import func_desc
from app import app


@fixture
def test_client():
    logger.info(func_desc())
    with Client(app) as client:
        return client

