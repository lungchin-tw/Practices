from chalice import Chalice
import logging
from chalicelib.core import func_desc


app = Chalice(app_name='fehv-demo', debug=True)

logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)


@app.route('/')
def index():
    app.log.debug(f'{func_desc()}:{app.current_request.to_dict()}')
    return {'hello': 'fehv-demo'}


@app.route('/v1/driver/leaderboard', methods=['GET'])
def get_driver_leaderboard():
    from chalicelib.model.driver import leaderboard
    logger.info(f'LOGGER:{func_desc()}:{app.current_request.to_dict()}')
    return leaderboard


@app.route('/v1/team/leaderboard', methods=['GET'])
def get_team_leaderboard():
    from chalicelib.model.team import leaderboard
    logger.info(f'LOGGER:{func_desc()}:{app.current_request.to_dict()}')
    return leaderboard
