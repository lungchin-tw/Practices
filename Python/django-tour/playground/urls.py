from django.urls import path
from .views import *

# URL Configuration
urlpatterns = [
    path('hello/', hello),
]