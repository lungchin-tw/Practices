

from chalice import Blueprint, Response
from . import func_desc


import logging
logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)

logger.info(f'Loading {__file__}, __name__:{__name__}')

bp_cognito = Blueprint(__name__)


# congnito need the correct AWS_REGION, can't use a fake region name
@bp_cognito.route('/cognito/login', methods=['POST'])
def cognito_login():
    import boto3
    import os

    logger.info(
        f'{func_desc()}, Region:{os.environ["AWS_REGION"]}, PoolId={os.environ["IDENTITY_POOL_ID"]}',
    )

    client = boto3.client(
        'cognito-identity',
        region_name=os.environ["AWS_REGION"],
    )
    id = client.get_id(IdentityPoolId=os.environ["IDENTITY_POOL_ID"])
    credential = client.get_credentials_for_identity(IdentityId=id['IdentityId'])
    return Response(
        status_code=200,
        body={
            'desc': func_desc(),
            'id': f'{id}',
            'credential': f'{credential}',
        }
    )
