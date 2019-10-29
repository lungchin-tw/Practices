# Author: Jacky


import sys
print( '\n{}\n'.format( sys.version ) )


try:
    print(x)
except NameError as e:
    print( 'Exception: NameError, {}'.format(e) )
except Exception as e:
    print( 'An exception occurred!!!' )
finally:
    print( 'Finally block.' )


print( '' )

x = -1

try:
    if x == -1:
        raise Exception( 'Error: x is invalid!!' )
except Exception as e:
    print( e )
