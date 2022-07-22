import json, os, logging, base64

logger = logging.getLogger()
logger.setLevel(logging.INFO)
logger.info(f'Loading {__file__}')

def handler(event, context):
    logger.info(f'event: {event}')
    logger.info(f'env: {os.environ.copy()}')
    body = event.get('body')
    isbase64 = event.get('isBase64Encoded')
    if isbase64 == True:
        body = base64.b64decode(body)

    body_json=json.loads(body)

    obj = {
        'event-action': f'{event.get("action")}',
        'eventType': f'{type(event)}',
        'contextType': f'{type(context)}',
        'body':f'{body}',
        'body-json': body_json,
        'body-action': body_json["action"],
        'isBase64Encoded': isbase64
    }

    return {
        'statusCode': 200,
        'body': json.dumps(obj),
    }