
from chalice import Blueprint

from .core import func_desc

print(f'Loading {__file__}')
print(f'__name__: {__name__}')

bpapi = Blueprint(__name__)

@bpapi.route('/bp')
def hello():
    print(f'{func_desc()}')
    return {'hello': 'blueprint'}