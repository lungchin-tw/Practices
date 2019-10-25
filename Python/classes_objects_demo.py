# Author: Jacky


import sys
print( '\n{}\n'.format( sys.version ) )


class Actor:
    x = 0
    y = 0

    def __init__( self, name, age ):
        self.name = name
        self.age = age

    def introduction( self ):
        return '{{ name:{}, age:{}, x:{}, y:{} }}'.format( self.name, self.age, self.x, self.y )


an_actor = Actor( 'Jacky', 43 )
print( 'an_actor: {}'.format( an_actor.introduction() ) )

    
