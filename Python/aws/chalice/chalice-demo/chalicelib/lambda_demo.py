

from chalice import Blueprint, Response
from . import func_desc

import logging
logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)

logger.info(f'Loading {__file__}, __name__:{__name__}')

BpLambda = Blueprint(__name__)

@BpLambda.lambda_function()
def foo(event, context):
    logger.info(func_desc())
    return Response(
        status_code=200,
        body={ 
            'desc': func_desc(),
            'event': f'{event}',
        }
    )