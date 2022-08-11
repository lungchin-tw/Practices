from chalice import Blueprint, Rate

from .core import func_desc

print(f'Loading {__file__}')
print(f'__name__: {__name__}')

bpevent = Blueprint(__name__)

@bpevent.schedule(Rate(1, Rate.MINUTES))
def every_min(event):
    print({
        'desc': func_desc(),
        'event': f'{event}',
    })

