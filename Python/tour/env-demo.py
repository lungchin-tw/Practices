
import sys
import platform
from pathlib import Path

print(f'platform.python_implementation():{platform.python_implementation()}')
print(f'platform.python_compiler():{platform.python_compiler()}')
print(f'platform.python_build():{platform.python_build()}')
print(f'platform.python_version_tuple():{platform.python_version_tuple()}')
print(f'platform.python_version():{platform.python_version()}')
print(f'platform.python_branch():{platform.python_branch()}')
print(f'platform.python_revision():{platform.python_revision()}')

print(f'sys.path:{sys.path}')
print(f'sys.version_info:{sys.version_info}')
print(f'__file__: {__file__}')
print(f'Path(__file__): {Path(__file__)}')
print(f'Path(__file__).resolve(): {Path(__file__).resolve()}')
print(f'Path(__file__).resolve().parent: {Path(__file__).resolve().parent}')
print(f'__annotations__: {__annotations__}')
print(f'__name__: {__name__}')
print(f'__package__: {__package__}')
print(f'__spec__: {__spec__}')

import sys, json
frame = sys._getframe()
print(f'frame.f_lasti: {frame.f_lasti}')
print(f'frame.f_lineno: {frame.f_lineno}')

code = frame.f_code
print(f'code.co_argcount: {code.co_argcount}')
print(f'code.co_cellvars: {code.co_cellvars}')
print(f'code.co_filename: {code.co_filename}')
print(f'code.co_firstlineno: {code.co_firstlineno}')
print(f'code.co_flags: {code.co_flags}')
print(f'code.co_freevars: {code.co_freevars}')
print(f'code.co_kwonlyargcount: {code.co_kwonlyargcount}')
print(f'code.co_name: {code.co_name}')
print(f'code.co_nlocals: {code.co_nlocals}')
print(f'code.co_varnames: {code.co_varnames}')
print(f'code.co_posonlyargcount: {code.co_posonlyargcount}')
print(f'code.co_stacksize: {code.co_stacksize}')



