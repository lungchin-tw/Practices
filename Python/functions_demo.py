# Author: Jacky


import sys
print( '\n{}\n'.format( sys.version ) )


def a_function( name, country = 'Taiwan' ):
    result = '{{ name: {}, country: {} }}'.format( name, country )
    print( result )
    return result


return_value = a_function( 'Jacky' )
print( 'return_value: {}'.format( return_value ) )

print( '' )

return_value = a_function( 'Sato', 'Japan' )
print( 'return_value: {}'.format( return_value ) )

print( '' )

def pass_var_len_args_function( *args ):
    for arg in args:
        print( '{} in args'.format( arg ) )

pass_var_len_args_function( 'Taipei', 'Tokyo', 'New York' )


print( '' )

a_square_lambda = lambda a : a * a

print( 'a_square_lambda(5): {}'.format( a_square_lambda( 5 ) ) )
