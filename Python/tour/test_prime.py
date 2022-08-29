
"""
Try pytest -vv --cache-clear --durations=0 ./test_prime.py
"""
import sys
from core import *


logger = getLogger(__name__)
logger.info(f'\n\
Loading {__file__}\n\
__name__:{__name__}\n\
sys.version: {sys.version}')


def is_prime_v1(n) -> bool:
    if n <= 1:
        return False

    for d in range(3, n):
        if (n % d) == 0:
            return False

    return True


import math

def is_prime_v2(n) -> bool:
    if n <= 1:
        return False
    elif n == 2:
        return True
    elif (n & 0x1) == 0:
        return False

    max_d = math.floor(math.sqrt(n))

    for d in range(3, max_d+1, 2):
        if (n % d) == 0:
            return False

    return True

MAX = 100000

def test_prime_v1():
    result = list()
    for n in range(2, MAX):
        if is_prime_v1(n):
            result.append(n)

    # logger.info(f'Result:{result}')


def test_prime_v2():
    result = list()
    for n in range(2, MAX):
        if is_prime_v2(n):
            result.append(n)

    # logger.info(f'Result:{result}')

