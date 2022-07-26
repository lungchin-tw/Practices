# Author: Jacky


import sys
print( '\n{}\n'.format( sys.version ) )


a_list = [ 'apple', 'bear', 'cookie' ]

print( 'The length of a_list: {}'.format( len(a_list) ) )

print( '' )

# For loop
print( 'The items of a_list:' )
for elem in a_list:
    print( elem )

print( '' )

# Copy a list( for Python3 )
a_list_copy = a_list.copy()
print( 'a_list_copy is a_list: {}'.format( a_list_copy is a_list ) )

print( '' )

# Create tuple with one item
a_one_item_tuple = ( 'apple', )
print( 'type(a_one_item_tuple): {}'.format( type( a_one_item_tuple ) ) )

not_a_tuple = ( 'apple' )
print( 'type(not_a_tuple): {}'.format( type( not_a_tuple ) ) )