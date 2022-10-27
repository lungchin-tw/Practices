
from chalicelib import func_desc
import http
import logging
logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)


logger.info(f'Loading {__file__}, __name__:{__name__}')


def test_auth_allow(test_client):
    logger.info(func_desc())
    rsp = test_client.http.get(
        '/auth/authorizer',
        headers={
            'Accept': '*/*',
            'Authorization': 'allow',
        },
    )
    logger.info(f'Status:{rsp.status_code}, Body:{rsp.json_body}')
    assert rsp.status_code == http.HTTPStatus.OK


def test_auth_forbidden(test_client):
    logger.info(func_desc())
    rsp = test_client.http.get(
        '/auth/authorizer',
        headers={
            'Accept': '*/*',
            'Authorization': 'deny',
        },
    )
    logger.info(f'Status:{rsp.status_code}, Body:{rsp.json_body}')
    assert rsp.status_code == http.HTTPStatus.FORBIDDEN


def test_auth_unauthorized(test_client):
    logger.info(func_desc())
    rsp = test_client.http.get(
        '/auth/authorizer',
        headers={
            'Accept': '*/*',
        },
    )
    logger.info(f'Status:{rsp.status_code}, Body:{rsp.json_body}')
    assert rsp.status_code == http.HTTPStatus.UNAUTHORIZED
