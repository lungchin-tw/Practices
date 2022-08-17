
import logging
logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)
logger.info(f'Loading: {__file__}, __name__:{__name__}')

from chalicelib.core import func_desc

from chalice import (
    Chalice,
    Response,
)


import http, requests
from chalice.app import ConvertToMiddleware
from aws_lambda_powertools import Logger, Tracer


app = Chalice(app_name='jacky-chen-chalice-lambda-powertools')
pt_logger = Logger()
pt_tracer = Tracer()
session = requests.Session()

app.register_middleware(ConvertToMiddleware(pt_logger.inject_lambda_context))
app.register_middleware(ConvertToMiddleware(pt_tracer.capture_lambda_handler))

@app.middleware('http')
def inject_route_info(event, get_response):
    logger.info(f'Desc: {func_desc()}')
    pt_logger.structure_logs(append=True, request_path=event.path)
    return get_response(event)


@app.route('/')
def index():
    logger.info(f'Desc: {func_desc()}')
    return Response(
        status_code=http.HTTPStatus.OK,
        body={
            'desc': func_desc(),
            'hello': app.app_name,
        },
    )


import random

BASE_URL = 'https://httpbin.org'

@app.route('/proxy/http')
def greetings():
    pt_logger.debug(f'Desc: {func_desc()}')
    if random.random() < 0.1:
        path = '/status/500'
    else:
        path = '/status/200'

    url = f'{BASE_URL}/{path}'
    response = session.get(url)
    pt_logger.debug(
        {
            'url': url,
            'status': response.status_code,
        },
    )

    response.raise_for_status()

    return Response(
        status_code=http.HTTPStatus.OK,
        body={
            'desc': func_desc(),
            'hello': app.app_name,
        },
    )
