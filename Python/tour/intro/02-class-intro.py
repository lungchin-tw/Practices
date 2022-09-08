
from democlass import DemoClass

lisa = DemoClass('Lisa')
lisa.instance_method()
print(f'{lisa.name = }')

choco = DemoClass('Choco')
print(f'{choco.name = }')
choco.name = 'New Choco'
print(f'{choco.name = }')

print(f'{DemoClass.static_method() = }')
print(f'{DemoClass.getCounter() = }')



