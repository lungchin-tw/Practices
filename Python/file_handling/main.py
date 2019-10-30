# Author: Jacky


import sys
print( '\n{}\n'.format( sys.version ) )

import os

cd = os.path.dirname( __file__ )
print( 'cd: {}\n'.format( cd ) )
print( 'cwd: {}\n'.format( os.getcwd() ) )

print( '' )

print( '__file__:{}'.format( __file__ ) )
print( 'os.path.abspath(__file__):{}'.format( os.path.abspath(__file__) ) )
print( 'os.path.dirname(os.path.abspath(__file__)):{}'.format( os.path.dirname(os.path.abspath(__file__)) ) )
print( 'os.path.dirname(os.path.dirname(os.path.abspath(__file__))):{}'.format( os.path.dirname(os.path.dirname(os.path.abspath(__file__))) ) )
print( 'os.path.join( cd, \'fafafa.json\' ): {}', os.path.join( cd, 'fafafa.json' ) )

print( '' )

# open file
f = open( os.path.join( cd, 'fafafa.json' ) )
context = f.read()
print( context )

print( '' )

# convert json to an object
import json
obj = json.loads( context )

print( obj )
print( type(obj) )
