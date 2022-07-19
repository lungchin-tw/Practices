from chalice import Chalice
from boto3.session import Session
from chalice import WebsocketDisconnectedError
import json

app = Chalice(app_name='jacky-chen-chalice-echo-server')
app.debug = True
app.websocket_api.session = Session()
app.experimental_feature_flags.update(['WEBSOCKETS'])

def event2dict(event):
    return {
        'domain_name': event.domain_name,
        'stage':event.stage,
        'connection_id': event.connection_id,
        'body': event.body,
    }

@app.on_ws_message()
def message(event):
    print(f'Message: {json.dumps(event2dict(event))}')
    try:
        app.websocket_api.send(
            connection_id=event.connection_id,
            message=event.body,
        )
    except WebsocketDisconnectedError as e:
        print(f'Message, Error: {e}')
    
@app.on_ws_connect()
def connect(event):
    print(f'Connected: {json.dumps(event2dict(event))}')

@app.on_ws_disconnect()
def disconnect(event):
    print(f'Disconnected: {json.dumps(event2dict(event))}')