
from demomodel import *
from moto import mock_s3
from pytest import mark


def impl_test_s3_mock():
    import env

    key = 'JackyChen'
    model_input = DemoModel(
        'JackyChen',
        'Senior Online Engineer',
    )

    model_input.new_to_s3(env.bucket_name(), env.region())
    model_fetch = DemoModel(key)
    model_fetch.fetch_from_s3(env.bucket_name(), env.region())
    assert model_fetch.value == model_input.value


@mark.s3
@mock_s3
def test_s3_mock_deco(aws_credentials):
    impl_test_s3_mock()


@mark.s3
def test_s3_mock_context(aws_credentials):
    with mock_s3():
        impl_test_s3_mock()


@mark.s3
def test_s3_mock_raw(aws_credentials):
    mock = mock_s3()
    mock.start()
    impl_test_s3_mock()
    mock.stop()
