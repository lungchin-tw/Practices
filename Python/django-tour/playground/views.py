import imp
from django.shortcuts import render
from django.http import HttpResponse

# Create your views here.
# Request -> Response
# Request Handler

def hello(request):
    print('hello')
    return render(request, 'hello.html', {'name': 'Jacky'})
