
from pathlib import Path

print(f'__file__: {__file__}')
print(f'Path(__file__): {Path(__file__)}')
print(f'Path(__file__).resolve(): {Path(__file__).resolve()}')
print(f'Path(__file__).resolve().parent: {Path(__file__).resolve().parent}')
print(f'__annotations__: {__annotations__}')
print(f'__name__: {__name__}')
print(f'__package__: {__package__}')
print(f'__spec__: {__spec__}')