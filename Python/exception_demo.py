# Author: Jacky


import sys
print( '\n{}\n'.format( sys.version ) )


try:
    print(x)
except NameError:
    print( 'Exception: NameError' )
except:
    print( 'An exception occurred!!!' )
finally:
    print( 'Finally block.' )


x = -1

if x == -1:
    raise Exception( 'Error: x is invalid!!' )
