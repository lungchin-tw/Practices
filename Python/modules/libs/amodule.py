# Author: Jacky


import sys
print( '\n{}\n'.format( sys.version ) )

from inspect import currentframe, getframeinfo

def greeting( name ):
    frameinfo = getframeinfo(currentframe())
    print( 'doc:{}, type:{}, method:{} file:{}:{}, name:{}, package:{}'.format( 
            __doc__,
            type( greeting ),
            frameinfo.function,
            frameinfo.filename,
            frameinfo.lineno,
            __name__,
            __package__ 
        ) )

    print( 'Hello, {}'.format( name ) )


class Actor:
    x = 0
    y = 0

    def __init__( self, name, age ):
        self.name = name
        self.age = age

        frameinfo = getframeinfo(currentframe())
        print( 'doc:{}, class:{}, method:{} file:{}:{}, name:{}, package:{}'.format( 
            __doc__,
            type(self),
            frameinfo.function,
            frameinfo.filename,
            frameinfo.lineno,
            __name__,
            __package__ 
        ) )

    def introduction( self ):
        frameinfo = getframeinfo(currentframe())
        print( 'doc:{}, class:{}, method:{} file:{}:{}, name:{}, package:{}'.format( 
            __doc__,
            type(self),
            frameinfo.function,
            frameinfo.filename,
            frameinfo.lineno,
            __name__,
            __package__ 
        ) )

        return '{{ name:{}, age:{}, x:{}, y:{} }}'.format( self.name, self.age, self.x, self.y )