
from core import *

logger = getLogger(__name__)
logger.setLevel(logging.DEBUG)
logger.info(f'Loading {__file__}, __name__:{__name__}')

class Student:
    def __init__(self, name, grade):
        logger.info(func_desc(self))
        self._name = name
        self._grade = grade

    @property
    def name(self):
        logger.info(func_desc(self))
        return self._name

    @property
    def grade(self):
        logger.info(func_desc(self))
        return self._grade

    @grade.setter
    def grade(self, value):
        logger.info(f'Setter: {func_desc(self)}')
        self._grade = value

    @property
    def info(self):
        logger.info(func_desc(self))
        return f'{self.name} got grade {self.grade}'


def test_property_decorator():
    logger.info(func_desc())
    nia = Student('Nina', 'B')
    logger.info(nia.info)

    nia.grade = 'A'
    logger.info(nia.info)

    