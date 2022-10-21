
from pytest import mark
from chalicelib import func_desc
import http
import logging
logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)


logger.info(f'Loading {__file__}, __name__:{__name__}')


@mark.leaderboard
def test_api_driver_leaderboard(test_client):
    logger.info(func_desc())
    rsp = test_client.http.get(
        '/v1/driver/leaderboard',
        headers={'Accept': '*/*'},
    )
    logger.info(f'Status:{rsp.status_code}, Body:{rsp.body}')
    assert rsp.status_code == http.HTTPStatus.OK


@mark.leaderboard
def test_api_team_leaderboard(test_client):
    logger.info(func_desc())
    rsp = test_client.http.get(
        '/v1/team/leaderboard',
        headers={'Accept': '*/*'},
    )
    logger.info(f'Status:{rsp.status_code}, Body:{rsp.body}')
    assert rsp.status_code == http.HTTPStatus.OK
