
import logging
logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)
logger.info(f'Loading: {__file__}, __name__:{__name__}')


from pynamodb.models import Model
from pynamodb.indexes import GlobalSecondaryIndex, AllProjection
from pynamodb.attributes import (
    UnicodeAttribute, NumberAttribute, UTCDateTimeAttribute
)

from datetime import datetime, timezone

def nowutc():
    return datetime.now(timezone.utc)


class DemoGSI(GlobalSecondaryIndex):
    class Meta:
        read_capacity_units = 1
        write_capacity_units = 1
        projection=AllProjection()

    name = UnicodeAttribute(hash_key=True)
    age = NumberAttribute(range_key=True)

class DemoUser(Model):
    class Meta:
        read_capacity_units = 1
        write_capacity_units = 1
        table_name = 'JackyDemoPynamoDB'
        region = "eu-central-1"

    userid = UnicodeAttribute(hash_key=True)
    name = UnicodeAttribute(range_key=False)
    age = NumberAttribute(default=0)
    created = UTCDateTimeAttribute(default=nowutc)
    gsi_name_age = DemoGSI()



def test_create_table():
    if not DemoUser.exists():
        DemoUser.create_table(wait=True)

    logger.info(f'DemoUser.describe_table():{DemoUser.describe_table()}')


def test_create_item():
    assert DemoUser.exists() == True

    DemoUser(
        userid='1000',
        name='Jacky',
        age=46,
    ).save()

    DemoUser(
        userid='1001',
        name='Vivian',
        age=53,
    ).save()

    


def test_get_item():
    assert DemoUser.exists() == True
    item = DemoUser.get('1000')
    logger.info(f'item:{item.attribute_values}')
    
    for item in DemoUser.gsi_name_age.query('Vivian'):
        logger.info(f'item:{item.attribute_values}')


def test_delete_table():
    if DemoUser.exists():
        DemoUser.delete_table()