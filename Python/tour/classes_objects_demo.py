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

# assign by parameters's order
an_actor_vivian = Actor( 'Vivian', 50 )
print( 'an_actor_vivian: {}'.format( an_actor_vivian.introduction() ) )

# assign by each parameter's name
an_actor_jacky = Actor( age=43, name='Jacky' )
print( 'an_actor_jacky: {}'.format( an_actor_jacky.introduction() ) )

    
# Simple inheritance
class StuntActor( Actor ):
    stutntSkill = ''

    def __init__( self, name, age, skill ):
        super().__init__( name, age )
        self.stutntSkill = skill

    def introduction( self ):
        info = super().introduction()
        return '{{ Actor:{}, stuntSkill:{} }}'.format( info, self.stutntSkill )


print( '' )

an_stunt_actor = StuntActor( 'Mary', 30, 'rolling' )
print( 'an_stunt_actor: {}'.format( an_stunt_actor.introduction() ) )