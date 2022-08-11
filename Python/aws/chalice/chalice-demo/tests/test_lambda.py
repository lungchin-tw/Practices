
import http, logging
logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)

from chalicelib import func_desc
from chalice.test import Client
from app import app


logger.info(f'Loading {__file__}, __name__:{__name__}')

def test_lambda_foo_func():
    logger.info(func_desc())
    with Client(app) as client:
        rsp = client.lambda_.invoke('foo')
        payload = rsp.payload
        logger.info(f'Status:{payload.status_code}, Body:{payload.body}')
        assert payload.status_code == http.HTTPStatus.OK
