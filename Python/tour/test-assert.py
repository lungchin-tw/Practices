
# Try python ./test-assert.py
# Try python -O ./test-assert.py
# Try export PYTHONOPTIMIZE=1; python ./test-assert.py

print(f'{__debug__ = }')
x = True
print(f'x: {x}')
assert x == None, f'X={x}, not None'