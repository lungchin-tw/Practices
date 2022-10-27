from chalicelib import func_desc
import http
import logging
logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)


logger.info(f'Loading {__file__}, __name__:{__name__}')


def test_cognito_login(test_client, aws_credentials, cognito_identity):
    logger.info(func_desc())
    rsp = test_client.http.post(
        '/cognito/login',
        headers={
            'Accept': '*/*',
        },
    )
    logger.info(f'Status:{rsp.status_code}, Body:{rsp.json_body}')
    assert rsp.status_code == http.HTTPStatus.OK