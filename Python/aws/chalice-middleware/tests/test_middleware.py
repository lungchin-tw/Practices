
import logging, http
from uuid import uuid4
logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)
logger.info(f'Loading: {__file__}, __name__:{__name__}')


from chalicelib.core import *
from . import test_client


def test_middleware_http(test_client):
    logger.info(f'Desc: {func_desc()}')
    rsp = test_client.http.get('/')
    logger.info(f'Status:{rsp.status_code}, Body:{rsp.json_body}')
    assert rsp.status_code == http.HTTPStatus.OK


def test_middleware_http_error_case_1(test_client):
    logger.info(f'Desc: {func_desc()}')
    rsp = test_client.http.get('/err/case1')
    logger.info(f'Status:{rsp.status_code}, Body:{rsp.json_body}')
    assert rsp.status_code == http.HTTPStatus.INTERNAL_SERVER_ERROR


def test_middleware_http_error_case_2(test_client):
    logger.info(f'Desc: {func_desc()}')
    rsp = test_client.http.get('/err/case2')
    logger.info(f'Status:{rsp.status_code}, Body:{rsp.json_body}')
    assert rsp.status_code == http.HTTPStatus.INTERNAL_SERVER_ERROR


def test_middleware_sns(test_client):
    logger.info(f'Desc: {func_desc()}')
    rsp = test_client.lambda_.invoke(
        'handle_sns_message',
        test_client.events.generate_sns_event(
            subject='UUID',
            message=f'{str(uuid4())}',
        ),
    )
    payload = rsp.payload
    logger.info(f'Status:{payload.status_code}, Body:{payload.body}')
    assert payload.status_code == http.HTTPStatus.OK


def test_middleware_exception(test_client):
    logger.info(f'Desc: {func_desc()}')
    rsp = test_client.lambda_.invoke('throw_exception')
    payload = rsp.payload
    logger.info(f'Status:{payload.status_code}, Body:{payload.body}')
    assert payload.status_code == http.HTTPStatus.INTERNAL_SERVER_ERROR
