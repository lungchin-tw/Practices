# Author: Jacky


import sys
print( '\n{}\n'.format( sys.version ) )


# A Simple Generator Example

def fruit_list():
    yield 'Apple'
    yield 'Banana'
    yield 'Orange'


result = fruit_list()
print( 'result: {}'.format( result ) )
print( 'list(result): {}'.format( list(result) ) )

print( '' )

result = fruit_list()
for value  in result:
    print( 'value: {}'.format( value ) )

print( '' )

try:
    print( 'next(result): {}'.format(next(result)) )
except StopIteration:
    print( 'Exception: StopIteration' )
    

print( '' )

# Another way to define a generator
num_list = [ 1, 2, 3, 4 ]
result = (x * x for x in num_list)
print( 'result: {}'.format(result) )
print( 'list(result): {}'.format( list(result) )  )
