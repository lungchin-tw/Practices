# Author: Jacky


import sys
print( '\n{}\n'.format( sys.version ) )


import libs.amodule as amodule


amodule.greeting( 'Jacky' )

print( '' )

actor = amodule.Actor( 'Mary', 30 )
actor.introduction()

print( '' )

# Builtin modules
print( 'Builtin modules:' )

import platform
print( 'platform.system():{}'.format( platform.system() ) )
print( 'dir(platform):\n{}'.format( dir(platform) ) )