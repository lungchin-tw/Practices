
import boto3
import logging
logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)
logger.info(f'Loading: {__file__}, __name__:{__name__}')


class DemoModel(object):
    @property
    def name(self) -> str:
        return self._name

    @property
    def value(self) -> str:
        return self._value

    def __init__(self, name: str, value: str = None):
        self._name = name
        self._value = value

    def new_to_s3(self, bucket_name: str, region: str):
        s3 = boto3.client('s3', region_name=region)
        constraint = {'LocationConstraint': region}
        s3.create_bucket(
            Bucket=bucket_name,
            CreateBucketConfiguration=constraint,
        )

        logger.info(f'Region:{region}, All Bucket:{s3.list_buckets()}')
        s3.put_object(Bucket=bucket_name, Key=self.name, Body=self.value)

    def fetch_from_s3(self, bucket_name: str, region: str):
        s3 = boto3.client('s3', region_name=region)
        rsp = s3.get_object(Bucket=bucket_name, Key=self.name)
        logger.info(f'GetObject:{rsp}')
        self._value = rsp['Body'].read().decode('utf-8')
        logger.info(f'FetchedValue:{self.value}')
