
from core import *

logger = getLogger(__name__)
logger.setLevel(logging.DEBUG)
logger.info(f'Loading {__file__}, __name__:{__name__}')

class Student:
    @staticmethod
    def static_method() -> str:
        return 'this is a static method.'


    _class_counter = 0 # class variable

    @classmethod
    def getCounter(cls):
        return cls._class_counter

    def __init__(self, name, grade):
        logger.info(func_desc(self))
        self._name = name
        self._grade = grade
        Student._class_counter += 1

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
    logger.info(Student.static_method())
    nina = Student('Nina', 'B')
    logger.info(f'Student.getCounter():{Student.getCounter()}, nia.getCounter():{nina.getCounter()}')

    logger.info(nina.info)

    
    