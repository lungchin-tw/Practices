import os
import boto3
from chalice import Chalice


app = Chalice(app_name='chalice-cdkdemo')
dynamodb = boto3.resource('dynamodb')
dynamodb_table = dynamodb.Table(os.environ.get('APP_TABLE_NAME', ''))


@app.route('/users', methods=['POST'])
def create_user():
    body = app.current_request.json_body
    item = {
        'PK': 'User#%s' % body['username'],
        'SK': 'Profile#%s' % body['username'],
    }
    item.update(body)
    dynamodb_table.put_item(Item=item)
    return {}


@app.route('/users/{username}', methods=['GET'])
def get_user(username):
    key = {
        'PK': 'User#%s' % username,
        'SK': 'Profile#%s' % username,
    }
    item = dynamodb_table.get_item(Key=key)['Item']
    del item['PK']
    del item['SK']
    return item
