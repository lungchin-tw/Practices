
import logging
logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)
logger.info(f'Loading: {__file__}, __name__:{__name__}')


from chalicelib.core import *
from . import test_client


def test_powertools(test_client):
    stats = {}
    logger.info(f'Desc: {func_desc()}')
    for x in range(100):
        rsp = test_client.http.get(
            '/proxy/http',
            headers={'Accept': '*/*'})
        logger.info(f'({x})Status: {rsp.status_code}')
        key = f'{rsp.status_code}'
        if key not in stats:
            stats[key] = 1
        else:
            stats[key] = stats[key] + 1

    logger.info(f'Stats: {stats}')
     