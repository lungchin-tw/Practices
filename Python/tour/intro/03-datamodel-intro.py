
"""
    Demo Dynamic Typing & type hopping
"""

x: int = 123
print(f'x = {x}, type(x)={type(x)}')

x = '123'
print(f'x = {x}, type(x)={type(x)}')




from democlass import DemoClass

lisa = DemoClass('Lisa')

print(f'lisa: {lisa}')
print(f'type of lisa: {type(lisa)}')
print(f'fype of DemoClass: {type(DemoClass)}')
