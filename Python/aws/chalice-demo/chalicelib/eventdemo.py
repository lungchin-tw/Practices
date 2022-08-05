
from requests import Response
from chalicelib import *
from chalice import Blueprint, Response

import http, logging
logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)

logger.info(f'Loading {__file__}, __name__:{__name__}')

BpEvent = Blueprint(__name__)

@BpEvent.on_sns_message(topic='jacky-chen-sns-demo')
def handle_sns_message(event):
    body={
        'Subject': event.subject,
        'Message': event.message,
    }
    
    BpEvent.current_app.log.info(body)
    return Response(
        status_code=http.HTTPStatus.OK,
        body=body,
    )

@BpEvent.on_s3_event(
    bucket='jacky-chen-cloud-formation-demo',
    events=[
        's3:ObjectCreated:*',
        's3:ObjectRemoved:*',
    ],
)
def handle_s3_event(event):
    logger.info({
        'desc': func_desc(),
        'event': f'{event}',
    })
        