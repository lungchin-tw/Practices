
import os
print(f'os:{os.name}')

import sys
print(f'sys:{sys.version}')

from helper import stringify, validation
print(f'defs in stringify:{dir(stringify)}')

def execute(val, unit):
    print(stringify.days_to_units(int(val), unit))

import datetime
print(datetime.datetime.today())
 
while True:
    args = input("\nEnter [days:unit] ->\n").split(':')
    is_quit = validation.is_quit_command(args[0])
    print(f'Type(is_quit): {type(is_quit)}; Value: {is_quit}')
    if is_quit:
        break
    elif validation.validate(args[0]) == True:
        execute(args[0], args[1])
