
import os, json
from chalicelib import func_desc
from chalicelib.authdemo import BpAuth
from chalicelib.eventdemo import BpEvent
from chalicelib.lambda_demo import BpLambda

from chalice import Chalice, NotFoundError, Response
from urllib.parse import parse_qs

print(f'Loading {__file__}, __name__:{__name__}')

app = Chalice(app_name='jacky-chen-chalice-demo', debug=True)
app.register_blueprint(BpAuth)
app.register_blueprint(BpEvent)
app.register_blueprint(BpLambda)


@app.route('/env', methods=['GET'])
def env_get():
    environ_str = json.dumps(os.environ.copy(), indent=4)
    app.log.info(f'{func_desc()}, os.environ:{environ_str}')
    req = app.current_request
    return Response(
        status_code=200,
        body={
            'desc': func_desc(),
            'method': req.method,
            'app': app.app_name,
            'package': __package__,
            'spec': f'{__spec__}',
            'os.environ': environ_str,
            'context': req.context
        },
    )

@app.route('/', methods=['GET'])
def index_get():
    app.log.info(func_desc())
    req = app.current_request
    return Response(
            status_code = 200,
            headers={'Content-Type': 'text/plain'},
            body={
                'method': req.method,
                'app': app.app_name,
                'introspect':req.to_dict(),
            }
        )

@app.route('/', methods=['POST'], content_types=['application/x-www-form-urlencoded'])
def index_post():
    req = app.current_request
    parsed = parse_qs(req.raw_body.decode())
    return {
        'method': req.method,
        'app': app.app_name,
        'items': parsed.get('item', []),
    }

@app.route('/users/{name}', methods=['GET'])
def status_of_user(name):
    req = app.current_request
    return {
        'method': req.method,
        'user': name,
        }

@app.route('/users/{name}', methods=['DELETE'])
def del_user(name):
    req = app.current_request
    return {
        'method': req.method,
        'user': name,
        }

CACHE = {}
@app.route('/kv/{id}', methods=['GET', 'PUT'])
def data_of_user(id):
    req = app.current_request
    if req.method == 'PUT':
        CACHE[id] = req.json_body
        return {
                'method': req.method,
                'id': id,
                'kv': req.json_body,
                'cache': CACHE,
            }
    elif req.method == 'GET':
        try:
            return {
                'method': req.method,
                id: CACHE[id],
            }
        except KeyError:
            raise NotFoundError(id)


import json, gzip

app.api.binary_types.append('application/json')
app.log.info(f'typeof(app.api.binary_types):{type(app.api.binary_types)}')
app.log.info(f'app.api.binary_types:{app.api.binary_types}')

@app.route('/compress')
def compress():
    req = app.current_request
    obj={
        'method': req.method,
        'app': app.app_name,
        'introspect':req.to_dict(),
    }

    blob = json.dumps(obj).encode('utf-8')
    payload = gzip.compress(blob)
    return Response(
                status_code = 200,
                headers={
                    'Content-Type': 'application/json',
                    'Content-Encoding': 'gzip',
                },
                body=payload,
            )


@app.route('/cors', cors=True)
def cors():
    req = app.current_request
    return Response(
                status_code = 200,
                body={
                    'method': req.method,
                    'cors': True
                },
            )

import requests

@app.route('/deps')
def dep():
    resp = requests.get("https://google.com")
    app.log.info(f'Response:{resp}')
    return Response(
        status_code=200,
        body=resp.content
    )
