# Author: Jacky


import sys
print( '\n{}\n'.format( sys.version ) )

import os
cd = os.path.dirname( __file__ )
print( 'cd: {}\n'.format( cd ) )
print( 'cwd: {}\n'.format( os.getcwd() ) )

# open file
f = open( cd + '\\fafafa.json' )
context = f.read()
print( context )

print( '' )

# convert json to an object
import json
obj = json.loads( context )

print( obj )
print( type(obj) )
