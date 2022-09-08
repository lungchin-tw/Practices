"""
    Meta Class Demo:
"""


from core import *

class DemoMeta(type):
    def __new__(self, class_name, bases, attrs):
        print(func_desc())
        print(f'{self = }')
        print(f'{class_name = }')
        print(f'{bases = }')
        attrs['weight'] = 0
        print(f'{attrs = }')
        return type(class_name, bases, attrs)


class DemoDog(object, metaclass=DemoMeta):
    counter = 0


a = DemoDog()
b = DemoDog()

print(f'a.weight: {a.weight}')
print(f'b.weight: {b.weight}')