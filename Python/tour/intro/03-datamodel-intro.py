
# Every thing in Python is a object

"""
    Demo Dynamic Typing & type hopping
"""

print("="*30)
print("Demo Dynamic Typing & type hopping")
print("="*30)
x: int = 123
print(f'{x = }')
print(f'{x = }, {type(x) = }')

x = '123'
print(f'{x = }, {type(x) = }')


print(f'\n{"="*30}')
print("Demo Class")
print("="*30)

from democlass import DemoClass

lisa = DemoClass('Lisa')
lisa.age = 10
print(f'\n{lisa.age = }\n')

# choco = DemoClass('Choco')
# print(f'\n{choco.age = }\n')

print(f'\n{lisa = }\n')
print(f'\n{type(lisa) = }\n')
print(f'\n{type(DemoClass) = }\n')



