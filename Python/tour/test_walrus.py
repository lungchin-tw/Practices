
from core import *
import sys

logger = getLogger(__name__)
logger.info(f'Loading {__file__}, \
            __name__:{__name__}, \
            sys.version: {sys.version}')

MAX = 10
INTERVAL = 3


def test_wo_walrus_01():
    nums = [i for i in range(MAX)]
    i = 0
    collected = []
    while i < len(nums):
        val = nums[i]
        if (val % INTERVAL) == 0:
            collected.append(val)

        i += 1

    logger.info(f'Result:{collected}')


def test_walrus_01():
    nums = [i for i in range(MAX)]
    i = 0
    collected = []
    while i < len(nums):
        if (((val := nums[i]) % INTERVAL) == 0):
            collected.append(val)

        i += 1

    logger.info(f'Result:{collected}')



def test_wo_walrus_02():
    class generator:
        counter = 0
        def __next__(self) -> int:
            val = self.__class__.counter
            self.__class__.counter += 1
            return val
        

    gen = generator()
    nums = [ next(gen) for _ in range(MAX)]
    collected = [n for n in nums if (n % INTERVAL) == 0]
    logger.info(f'Result:{collected}')


def test_walrus_02():
    class generator:
        counter = 0
        def __next__(self) -> int:
            self.__class__.counter = (val := self.__class__.counter) + 1
            return val

    gen = generator()
    collected = [n for _ in range(MAX) if (((n := next(gen)) % INTERVAL) == 0)]
    logger.info(f'Result:{collected}')

