

from pytest import mark
import boto3
import logging

logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)
logger.info(f'Loading: {__file__}, __name__:{__name__}')


# congnito need the correct AWS_REGION, can't use a fake region name
@mark.cognito
def test_cognito_mock_deco(aws_credentials, cognito_identity):
    import env

    client = boto3.client('cognito-identity', region_name=env.region())
    desc = client.describe_identity_pool(IdentityPoolId=env.identity_pool_id())
    logger.info(f'DESC:{desc}')
    id = client.get_id(IdentityPoolId=env.identity_pool_id())
    logger.info(f'id:{id}')
    credential = client.get_credentials_for_identity(IdentityId=id['IdentityId'])
    logger.info(f'credential:{credential}')
