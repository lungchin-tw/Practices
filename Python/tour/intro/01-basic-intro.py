"""
    Module
"""
from core import *

print(f'\n{"="*20} Module {"="*20}')

msg = func_desc()
print(msg)

from core import const
print(f'dir(const):{dir(const)}')


print(f'\n{"="*20} Function {"="*20}')
"""
    Function
"""
def demo_func(msg):
    for i in range(const.MAX):
        print(f'{i}:{msg}')


# execute function
demo_func('How you doing?')


print(f'\n{"="*20} Exception {"="*20}')
"""
    Exception Handling
""" 
try:
    raise Exception('An Exception')
except Exception as e:
    print(f'Exception: {e}')
finally:
    print('Finally')
