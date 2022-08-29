"""
    Module
"""

from core import *

msg = func_desc()
print(msg)

from core import const
print(f'dir(const):{dir(const)}')


"""
    Function
"""
def demo_func(msg):
    for i in range(const.MAX):
        print(f'{i}:{msg}')


# execute function
demo_func('How you doing?')





