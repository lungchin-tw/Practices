
import core
from io import TextIOWrapper
from datetime import datetime

# User Case 1:
try:
    file = open('read.log', 'r')
    print(f'read read.log: {file.read()}')
except Exception as e:
    print('[read file]: exception')
    print(f'Exception: {e}')


# User Case 2:
file = open('nowith.log', 'a')
file.write(f'{datetime.now()}, greetings, no with-1\n')
file.close()

# User Case 3:
try:
    file = open('nowith.log', 'a')
    file.write(f'{datetime.now()}, greetings, no with-2\n')
finally:
    file.close()

with open('with.log', 'a') as file:
    file.write(f'{datetime.now()}, greetings, with\n')

# User Case 4:
class ResourceController(object):
    def __init__(self, filename) -> None:
        print(core.func_desc(self))
        self.filename = filename

    def __enter__(self) -> TextIOWrapper:
        print(core.func_desc(self))
        self.file = open(self.filename, 'a')
        return self.file

    def __exit__(self, exc_type, exc_value, traceback):
        print(f'{core.func_desc(self)}, exct_type:{exc_type}, exc_value:{exc_value}, traceback:{traceback}')
        self.file.close()



with ResourceController('resource.log') as resource:
    print(f'with statement:{core.func_desc()}')
    resource.write(f'{datetime.now()}, greetings, resource.\n')

