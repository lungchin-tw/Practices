from django.shortcuts import render
from django.http import HttpResponse
from inspect import currentframe, getframeinfo


def index(request):
    fi = getframeinfo(currentframe())
    msg = 'doc:{}, method:{} file:{}:{}, name:{}, package:{}, request:{}'.format( 
            __doc__,
            fi.function,
            fi.filename,
            fi.lineno,
            __name__,
            __package__,
            request
        )

    print( msg )

    return HttpResponse( 'Hello, world. You\'re at the polls index.\n Verbose:{}'.format( msg ) )
