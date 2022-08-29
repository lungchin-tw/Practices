
import logging
import sys

logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)
logger.info(f'Loading {__file__}, \
            __name__:{__name__}, \
            sys.version: {sys.version}')

MAX = 100
aggregate = [i**2 for i in range(MAX)]
logger.info(f'Size of Aggregate: {sys.getsizeof(aggregate)}')

class DemoGenerator:
    def __init__(self, n) -> None:
        self.n = n
        self.last = 0


    def __next__(self) -> int:
        return self.next()


    def next(self) -> int:
        if self.last == self.n:
            raise StopIteration()

        val = self.last ** 2
        self.last += 1
        return val


def test_generator():
    gen = DemoGenerator(MAX)
    logger.info(f'Size of Generator: {sys.getsizeof(gen)}')    
    
    str = '['
    while True:
        try:
            str = f'{str}{next(gen)}, '
        except StopIteration:
            break

    logger.info(f'{str}]')

def demo_yield(n):
    for i in range(n):
        yield i**2


def test_yield():
    gen = demo_yield(MAX)
    logger.info(f'Size of Yield: {sys.getsizeof(gen)}')

    str = '['
    for i in gen:
        str = f'{str}{next(gen)}, '

    logger.info(f'{str}]')