from curses.ascii import NUL
import chalicelib
from urllib import response

from chalice import Chalice, NotFoundError, Response
from urllib.parse import urlparse, parse_qs

app = Chalice(app_name=chalicelib.APP_NAME, debug=True)
app.log.info(f'Loading {__file__}')

@app.route('/', methods=['GET'])
def index_get():
    req = app.current_request

    env = {
        'desc': chalicelib.func_desc(None),
        'name': __name__,
        'package': __package__,
        'spec': f'{__spec__}',
    }
    return Response(
            status_code = 200,
            headers={'Content-Type': 'text/plain'},
            body={
                'method': req.method,
                'app': chalicelib.APP_NAME,
                'env': env,
                'introspect':req.to_dict(),
            }
        )

@app.route('/', methods=['POST'], content_types=['application/x-www-form-urlencoded'])
def index_post():
    req = app.current_request
    parsed = parse_qs(req.raw_body.decode())
    return {
        'method': req.method,
        'app': chalicelib.APP_NAME,
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
        'app': chalicelib.APP_NAME,
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