
import logging
import sys

logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)
logger.info(f'Loading {__file__}, \
            __name__:{__name__}, \
            sys.version: {sys.version}')

import timeit
import numpy

_NUM_RANGE_ = 1_000_000

def while_loop(n=_NUM_RANGE_):
    i = 0
    sum = 0
    while i < n:
        i += 1
        sum += i
    
    return sum


def for_loop(n=_NUM_RANGE_):
    sum = 0
    for i in range(n):
        sum += i
    
    return sum


def sum_range(n=_NUM_RANGE_):
    return sum(range(n))


def sum_numpy(n=_NUM_RANGE_):
    return numpy.sum(numpy.arange(n))


def test_timeit():
    logger.info(f'while loop: {timeit.timeit(while_loop, number=100)}')
    logger.info(f'for loop: {timeit.timeit(for_loop, number=100)}')
    logger.info(f'sum_range: {timeit.timeit(sum_range, number=100)}')
    logger.info(f'sum_numpy: {timeit.timeit(sum_numpy, number=100)}')