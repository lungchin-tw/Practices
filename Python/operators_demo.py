# Author: Jacky


import sys
print( sys.version )


a = 'How are you doing?'
b = 'How are you doing?'

c = [ 'apple', 'bear' ]
d = [ 'apple', 'bear' ]
e = c


print( 'ing in a: ' + (str('ing' in a )) )
print( 'ing not in a: ' + (str('ing' not in a )) )
print( 'a is b: ' + str(a is b) )
print( 'c is d: ' + str(c is d) )
print( 'c == d: ' + str(c == d) )
print( 'c != d: ' + str(c != d) )
print( 'e is c: ' + str(e is c) )
print( 'e is d: ' + str(e is d) )


print( '' )

# The results are different depends on the python version( 3 or 2 )
c = ( 'apple', 'bear' )
d = ( 'apple', 'bear' )
e = c
print( 'c is d: ' + str(c is d) )
print( 'c == d: ' + str(c == d) )
print( 'c != d: ' + str(c != d) )
print( 'e is c: ' + str(e is c) )
print( 'e is d: ' + str(e is d) )