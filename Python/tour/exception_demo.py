# Author: Jacky


import sys
print( '\n{}\n'.format( sys.version ) )


try:
    a = 1
    print(x)
except NameError as e:
    print( 'Exception: NameError, {}'.format(e) )
except Exception as e:
    print( 'An exception occurred!!!' )
finally:
    print( f'Finally block. a={a}' )


print( '' )

x = -1

try:
    if x == -1:
        raise Exception( 'Error: x is invalid!!' )
except Exception as e:
    print( e )
