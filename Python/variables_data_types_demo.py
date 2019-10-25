# Author: Jacky

# Python allows you to assign values to multiple variables in one line
x, y, z = 1, 2, 4

print( x )
print( y )
print( z )

# If you try to combine a string and a number, Python will give you an error
# print( 'x = ' + x ) <-- error
print( 'x = ' + str(x) )

print( x + y ) 


# Global Variables

gx = 'WTF!!!'

print( 'gx: ' + gx + ' in global' )

def a_func():
    print( 'gx: ' + gx + ' in a_func()' )

a_func()


def set_global():
    global gz
    gz = 'gz is a global variable set in function set_global()'

set_global()
print( 'gz: '+ gz )

print( 'bool(5) = ' + str(bool(5)) )
print( 'type(bool(5)) = ' + str(type(bool(5))) )

print( 'bytes(5) = ' + str(bytes(5)) )
print( 'type(bytes(5)) = ' + str(type(bytes(5))) )
print( 'bytearray(5) = ' + str(bytearray(5)) )
print( 'type(bytearray(5)) = ' + str(type(bytearray(5))) )
print( 'memoryview(bytes(5)) = ' + str(memoryview(bytes(5))) )
print( 'type(memoryview(bytes(5))) = ' + str(type(memoryview(bytes(5)))) )

