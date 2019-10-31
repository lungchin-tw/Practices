# Author Jacky

from django.urls import path
from . import views


app_name = 'polls'
urlpatterns = [
    path( '', views.index, name='index' ),
    path( 'index/v2/', views.index_v2, name='index_v2' ),
    path( 'index/v3/', views.index_v3, name='index_v3' ),
    path( '<int:question_id>/', views.detail, name='detail' ),
    path( '<int:question_id>/detail/v2/', views.detail_v2, name='detail_v2' ),
    path( '<int:question_id>/result/', views.result, name='result' ),
    path( '<int:question_id>/vote/', views.vote, name='vote' ),
]