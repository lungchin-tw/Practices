
import logging, http
logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)
logger.info(f'Loading: {__file__}, __name__:{__name__}')


from chalicelib.core import *
from . import test_client


def test_register_for_all(test_client):
    logger.info(f'Desc: {func_desc()}')
    rsp = test_client.http.get('/')
    logger.info(f'Status:{rsp.status_code}, Body:{rsp.json_body}')
    assert rsp.status_code == http.HTTPStatus.OK


def test_register_for_lambda(test_client):
    logger.info(f'Desc: {func_desc()}')
    rsp = test_client.lambda_.invoke('demo_register_for_lambda')
    payload = rsp.payload
    logger.info(f'Status:{payload.status_code}, Body:{payload.body}')
    assert payload.status_code == http.HTTPStatus.OK
