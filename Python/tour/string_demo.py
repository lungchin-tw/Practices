# Author: Jacky


import sys
print( sys.version )

# double and single quotation are both the same
print( "Hello world." )
print( 'Hello world.' )

# double and single quotation are both the same
mlstr = '''
line1,
and line2,
and line3...
'''
print( mlstr )


# Square brackets can be used to access elements of the string.
a = 'How are you doing?'
print( 'a[10]: ' + a[10] )

# Slice syntax
print( 'a[2:10]: ' + a[2:10] )
print( 'a[-5:-2]: ' + a[-5:-2] )

print( 'len(a): ' + str(len(a)) )

print( 'a.upper(): ' + a.upper() )

print( 'ing in a: ' + (str('ing' in a )) )
print( 'ing not in a: ' + (str('ing' not in a )) )


# String format
str_form = 'The len of string a:\'{}\' is {}'
print( str_form.format( a, len( a ) ) )

# String format with argument numbers
str_form = 'The len of string a:\'{1}\' is {0}'
print( str_form.format( len( a ) , a ) )