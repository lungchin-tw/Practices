
from demomodel import *
import env
import boto3
from moto import mock_s3
# from .conftest import *


def impl_test_s3_mock():
    model_input = DemoModel(
        'JackyChen',
        'Senior Online Engineer',
    )

    conn = boto3.resource('s3', env.REGION)
    model_input.new_to_s3(env.BUCKET_NAME, env.REGION)


@mock_s3
def test_s3_mock(aws_credentials):
    impl_test_s3_mock()
