import logging, http
logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)
logger.info(f'Loading: {__file__}, __name__:{__name__}')


from chalice import (
    Chalice,
    Response,
    ChaliceUnhandledError,
    ConvertToMiddleware,
)

from chalicelib.core import func_desc


app = Chalice(app_name='jacky-chen-chalice-middleware')

@app.middleware('')
def demo_middleware(event, get_response):
    try:
        logger.info({
            'desc': func_desc(),
            'msg': 'Before calling get_response'
        })

        rsp = get_response(event)

        logger.info({
            'desc': func_desc(),
            'msg': 'After calling get_response'
        })
        return rsp
    except RuntimeError as e:
        return Response(
            status_code=http.HTTPStatus.INTERNAL_SERVER_ERROR,
            body={
                'desc': func_desc(),
                'Exception': f'{e}',
            },
        )
    except ChaliceUnhandledError as e:
        return Response(
            status_code=http.HTTPStatus.INTERNAL_SERVER_ERROR,
            body={
                'desc': func_desc(),
                'Exception': f'{e}',
            },
        )


@app.route('/')
def index():
    logger.info(f'Desc: {func_desc()}')
    return {'hello': app.app_name}


@app.route('/err/case1')
def rest_err_case1():
    logger.info(f'Desc: {func_desc()}')
    raise Exception(func_desc())

@app.route('/err/case2')
def rest_err_chalice_unhandled_error():
    logger.info(f'Desc: {func_desc()}')
    raise ChaliceUnhandledError(func_desc())


@app.on_sns_message(topic='jacky-chen-chalice-middleware')
def handle_sns_message(event):
    logger.info({
        'desc': func_desc(),
        'event': f'{event}',
    })
    
    return Response(
        status_code=http.HTTPStatus.OK,
        body={
            'Subject': event.subject,
            'Message': event.message,
        },
    )


@app.lambda_function()
def throw_exception(event, context):
    logger.info(f'Desc: {func_desc()}')
    raise RuntimeError('Raising an error.')
