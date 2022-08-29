
from democlass import DemoClass

lisa = DemoClass('Lisa')
print(f'{lisa.name}')

choco = DemoClass('Choco')
print(f'{choco.name}')
choco.name = 'New Choco'
print(f'{choco.name}')

print(f'DemoClass::getCounter={DemoClass.getCounter()}')
print(f'DemoClass::counter={DemoClass.counter}')



