# Author: Jacky


import sys
print( '\n{}\n'.format( sys.version ) )

import datetime

now = datetime.datetime.now()
print( f'Now: {now}')
print( 'Now: {}'.format( now ) )
print( 'now.strftime( \'%A\' ): {}'.format( now.strftime( '%A' ) ) )
print( 'now.strftime( \'%B\' ): {}'.format( now.strftime( '%B' ) ) )
print( 'now.strftime( \'%d\' ): {}'.format( now.strftime( '%d' ) ) )
print( 'now.strftime( \'%p\' ): {}'.format( now.strftime( '%p' ) ) )
print( 'now.strftime( \'%z\' ): {}'.format( now.strftime( '%z' ) ) )
print( 'now.strftime( \'%Z\' ): {}'.format( now.strftime( '%Z' ) ) )
print( 'now.strftime( \'%j\' ): {}'.format( now.strftime( '%j' ) ) )
print( 'now.strftime( \'%U\' ): {}'.format( now.strftime( '%U' ) ) )
print( 'now.strftime( \'%W\' ): {}'.format( now.strftime( '%W' ) ) )
print( 'now.strftime( \'%c\' ): {}'.format( now.strftime( '%c' ) ) )

