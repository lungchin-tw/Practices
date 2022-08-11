
import logging, http, datetime
logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)
logger.info(f'Loading: {__file__}, __name__:{__name__}')

from chalice import Chalice, Response, ConvertToMiddleware
from chalicelib.core import func_desc

app = Chalice(app_name='jacky-chen-chalice-middleware-register')

@app.middleware('pure_lambda')
def inject_time(event, get_response):
    start = datetime.datetime.now()
    logger.info({
        'desc': func_desc(),
        'msg': 'Before calling get_response'
    })

    response = get_response(event)

    elapsed = datetime.datetime.now() - start
    logger.info({
        'desc': func_desc(),
        'msg': 'After calling get_response',
        'elapsed': f'{elapsed}, {elapsed.microseconds}',
    })
    
    return response


def log_invocation(func):
    def wrapper(event, context):
        logger.info({
            'desc': func_desc(),
            'msg': 'Before calling get_response'
        })

        response = func(event, context)

        logger.info({
            'desc': func_desc(),
            'msg': 'After calling get_response'
        })
        return response
    return wrapper

app.register_middleware(ConvertToMiddleware(log_invocation), event_type='all')



@app.route('/')
def index():
    logger.info(f'Desc: {func_desc()}')
    return Response(
        status_code=http.HTTPStatus.OK,
        body={
            'desc': func_desc(),
            'msg': f'hello, {app.app_name}',
        },
    )


@app.lambda_function()
def demo_register_for_lambda(event, context):
    logger.info(f'Desc: {func_desc()}')
    return Response(
        status_code=http.HTTPStatus.OK,
        body={
            'desc': func_desc(),
            'event': f'{event}',
            'context': f'{context}',
        },
    )
