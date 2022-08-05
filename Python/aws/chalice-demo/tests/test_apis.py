
import http, logging
logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)

from chalicelib import func_desc
from chalice.test import Client
from app import app

logger.info(f'Loading {__file__}, __name__:{__name__}')

def test_api_env():
    logger.info(func_desc())
    with Client(app) as client:
        rsp = client.http.get(
            '/env',
            headers={'Accept':'*/*'},
        )
        logger.info(f'Status:{rsp.status_code}, Body:{rsp.body}')
        assert rsp.status_code == http.HTTPStatus.OK
