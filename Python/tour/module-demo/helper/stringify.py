
# relative import - I
from .conf import units_a_day 
units_dict = units_a_day

# relative import - II
# from . import conf 
# units_dict = conf.units_a_day

def days_to_units(num_of_days, unit):
    val = units_dict[unit]
    result = num_of_days * val
    return f'{num_of_days} days are {result} {unit}s.'
