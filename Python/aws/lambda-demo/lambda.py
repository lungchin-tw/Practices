import json, os

def handler(event, context):
    action = event.get('action')
    obj = {
        'action': f'{action}',
        'eventType': f'{type(event)}',
        'contextType': f'{type(context)}',
        'event': f'{event}',
        'env': f'{os.environ.copy()}'
    }

    return {
        'statusCode': 200,
        'body': json.dumps(obj),
    }