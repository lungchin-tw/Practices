

from pytest import mark
import boto3
import logging

logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)
logger.info(f'Loading: {__file__}, __name__:{__name__}')


@mark.cognito
def test_cognito_mock_deco(aws_credentials, cognito_identity):
    import env

    client = boto3.client('cognito-identity', region_name=env.region())
    desc = client.describe_identity_pool(IdentityPoolId=env.identity_pool_id())
    logger.info(f'DESC:{desc}')
    client.get_id(IdentityPoolId=env.identity_pool_id())
    # client.get_credentials_for_identity(IdentityId=uid)
    # logger.info(f'id:{id}')
