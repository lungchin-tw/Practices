"""
WSGI config for djangotour project.

It exposes the WSGI callable as a module-level variable named ``application``.

For more information on this file, see
https://docs.djangoproject.com/en/4.0/howto/deployment/wsgi/
"""

import imp
import os
from django.core.wsgi import get_wsgi_application

os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'djangotour.settings')

application = get_wsgi_application()


import uwsgidecorators
import datetime
from .tasks import *

@uwsgidecorators.timer(10)
def periodic_task(singal: int):
    print(f'{__name__}.periodic_task, Signal:{singal}, Time:{datetime.datetime.now()}')
    


