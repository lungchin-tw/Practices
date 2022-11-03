
import os
import logging
logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)
logger.info(f'Loading {__file__}, __name__:{__name__}')

from chalicelib import func_desc

method = 'GET'
host = '96rbtt3mb6.execute-api.eu-central-1.amazonaws.com'
access_key = os.environ['AWS_ACCESS_KEY']
secret_key =os.environ['AWS_SECRET_KEY']
region = os.environ['AWS_REGION']
service = 'execute-api'
x_amz_date = 'x-amz-date'

import requests

def test_iam_auth_by_plugin():
    from aws_requests_auth.aws_auth import AWSRequestsAuth
    
    auth=AWSRequestsAuth(
        aws_access_key=access_key,
        aws_secret_access_key=secret_key,
        aws_host=host,
        aws_region=region,
        aws_service=service,
    )
    
    response = requests.request(method, f'https://{host}/dev/iam-auth', auth=auth)
    logger.info(f'{func_desc()}: {response.__dict__}')


import hashlib
import hmac

def sign(key, msg) -> bytes:
    return hmac.new(key, msg.encode('utf-8'), hashlib.sha256).digest()


def signatureKey(key, datestamp, region, service):
    keydate = sign(f'AWS4{key}'.encode('utf-8'), datestamp)
    keyregion = sign(keydate, region)
    keyservice = sign(keyregion, service)
    keysigning = sign(keyservice, 'aws4_request')
    return keysigning


def test_iam_auth_manual():
    import datetime
    now = datetime.datetime.utcnow()

    amzdate = datetime.datetime.utcnow().strftime('%Y%m%dT%H%M%SZ')
    logger.info(f'amzdate: {amzdate}')

    datestamp = now.strftime('%Y%m%d')
    logger.info(f'datestamp: {datestamp}')

    canonical_url ='/dev/iam-auth'
    canonical_querystring = ''
    canonical_headers = f'host:{host}\n{x_amz_date}:{amzdate}\n'
    logger.info(f'canonical_headers:\n{canonical_headers}')

    signed_headers=f'host;{x_amz_date}'

    payload = ''
    payload_hash = hashlib.sha256(payload.encode('utf-8')).hexdigest()
    logger.info(f'payload_hash: {payload_hash}')

    canonical_request = (
        f'{method}\n'
        f'{canonical_url}\n'
        f'{canonical_querystring}\n'
        f'{canonical_headers}\n'
        f'{signed_headers}\n'
        f'{payload_hash}'
    )

    logger.info(f'canonical_request: {canonical_request}')

    canonical_request_hash = hashlib.sha256(canonical_request.encode('utf-8')).hexdigest()
    logger.info(f'canonical_request_hash: {canonical_request_hash}')

    algorithm = 'AWS4-HMAC-SHA256'

    credential_scope = f'{datestamp}/{region}/{service}/aws4_request'
    logger.info(f'credential_scope: {credential_scope}')

    string_to_sign = (
        f'{algorithm}\n'
        f'{amzdate}\n'
        f'{credential_scope}\n'
        f'{canonical_request_hash}'
    )

    logger.info(f'string_to_sign: {string_to_sign}')

    signing_key = signatureKey(secret_key, datestamp, region, service)
    logger.info(f'signing_key: {signing_key}')

    signature = hmac.new(signing_key, string_to_sign.encode('utf-8'), hashlib.sha256).hexdigest()
    logger.info(f'signature: {signature}')

    auth_header = (
        f'{algorithm} Credential={access_key}/{credential_scope}, '
        f'SignedHeaders={signed_headers}, '
        f'Signature={signature}'
    )

    headers = {
        f'{x_amz_date}': amzdate,
        'Authorization': auth_header,
    }

    logger.info(f'headers: {headers}')

    response = requests.request(method, f'https://{host}{canonical_url}', headers=headers)
    logger.info(f'{func_desc()}: {response.__dict__}')

    