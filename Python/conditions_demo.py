# Author: Jacky


import sys
print( '\n{}\n'.format( sys.version ) )


a = 10
b = 20
c = 30

if ( a > b ):
    print( '{} > {}'.format( a, b ) )
elif ( a == b ):
    print( '{} == {}'.format( a, b ) )
else:
    print( '{} < {}'.format( a, b ) )


print( '' )

# Short hand syntax ( Python3 )
print( '{} > {}'.format( a, b ) ) if ( a > b ) else print( '{} <= {}'.format( a, b ) )

print( '' )

# And Operator
if ( ( a < c ) and ( b < c ) ):
    print( 'Both {} and {} are less than {}'.format( a, b, c ) )

print( '' )

c = 1
# Nested conditions
if ( a < c ):
    if ( b < c ):
        print( 'Both {} and {} are less than {}'.format( a, b, c ) )
    else:
        print( 'One of {} and {} are greater than {}'.format( a, b, c ) )
else:
    pass

print( '' )

i = 0
while ( i < 6 ):
    print( i )
    i += 1
else:
    print( 'i: {}'.format( i ) )


print( '' )

for index in range( 2, 10 ):
    print( '{} in range( 2, 10 )'.format( index ) )