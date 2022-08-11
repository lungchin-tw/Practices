from chalice import Chalice, WebsocketDisconnectedError

from boto3.session import Session

from chalicelib import Storage, Sender, Handler


app = Chalice(app_name='jacky-chen-chalice-chat-example')
app.debug = True

app.websocket_api.session = Session()
app.experimental_feature_flags.update(['WEBSOCKETS'])

STORAGE = Storage.from_env()
SENDER = Sender(app, STORAGE)
HANDLER = Handler(STORAGE, SENDER)

def event2dict(event):
    return {
        'domain_name': event.domain_name,
        'stage':event.stage,
        'connection_id': event.connection_id,
        'body': event.body,
    }

@app.on_ws_message()
def message(event):
    print(f'Message: {event2dict(event)}')
    HANDLER.handle(event.connection_id, event.body)    
    
@app.on_ws_connect()
def connect(event):
    print(f'Connected: {event2dict(event)}')
    STORAGE.create_connection(event.connection_id)

@app.on_ws_disconnect()
def disconnect(event):
    print(f'Disconnected: {event2dict(event)}')
    STORAGE.delete_connection(event.connection_id)