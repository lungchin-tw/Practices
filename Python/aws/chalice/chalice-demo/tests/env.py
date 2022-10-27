
import os


def region() -> str:
    return os.environ['AWS_REGION']


def bucket_name() -> str:
    return 'DemoBucket'


def identity_pool_name() -> str:
    return 'DemoIdentityPool'


def set_identity_pool_id(id: str):
    os.environ['IDENTITY_POOL_ID'] = id


def identity_pool_id() -> str:
    return os.environ['IDENTITY_POOL_ID']
