from core import *
import sys

logger = getLogger(__name__)
logger.info(f'Loading {__file__}, \
            __name__:{__name__}, \
            sys.version: {sys.version}')


def test_map():
    g = lambda x: x**2
    nums = [2, 5, 7.1, 0.3, 10]
    logger.info(f'Map: {list(map(g, nums))}')


import statistics
def test_filter():
    nums = [2, 5, 7.1, 0.3, 10]
    avg = statistics.mean(nums)
    logger.info(f'AVG: {avg}')
    logger.info(f'Filter: {list(filter(lambda x: x > avg, nums))}')


from functools import reduce
def test_reduce():
    data = [x for x in range(1, 10)]
    fun = lambda x, y: x+y
    logger.info(f'Data: {data}')
    logger.info(f'Reduce: {reduce(fun, data)}')