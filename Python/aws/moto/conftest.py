
import os
import boto3
from pytest import fixture
from moto import mock_cognitoidentity
import env
import logging

logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)
logger.info(f'Loading: {__file__}, __name__:{__name__}')


@fixture(scope="session")
def aws_credentials():
    """Mocked AWS Credentials for moto."""
    os.environ['AWS_ACCESS_KEY_ID'] = 'testing'
    os.environ['AWS_SECRET_ACCESS_KEY'] = 'testing'
    os.environ['AWS_SECURITY_TOKEN'] = 'testing'
    os.environ['AWS_SESSION_TOKEN'] = 'testing'
    os.environ["MOTO_ALLOW_NONEXISTENT_REGION"] = "True"
    os.environ["AWS_DEFAULT_REGION"] = 'taipei'


@fixture(scope="session")
def cognito_identity():
    with mock_cognitoidentity():
        client = boto3.client('cognito-identity', region_name=env.region())
        pool = client.create_identity_pool(
            IdentityPoolName=env.identity_pool_name(),
            AllowUnauthenticatedIdentities=True,
        )
        # client.get_id(IdentityPoolId=pool.get('IdentityPoolId'))

        env.set_identity_pool_id(pool.get('IdentityPoolId'))
        logger.info(f'Pool:{pool}')
        # pool_id = pool.get('IdentityPoolId')
        desc = client.describe_identity_pool(
            IdentityPoolId=env.identity_pool_id())
        logger.info(f'DESC:{desc}')
        yield
