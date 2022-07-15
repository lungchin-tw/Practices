import json

def handler(event, context):
    action = event.get('action')
    obj = {
        'action': f'{action}',
        'eventType': f'{type(event)}',
        'contextType': f'{type(context)}',
        'event': f'{event}',
    }

    return {
        'statusCode': 200,
        'body': json.dumps(obj),
    }