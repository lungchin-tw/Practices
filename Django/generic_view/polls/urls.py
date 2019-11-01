# Author Jacky

from django.urls import path
from . import views


app_name = 'polls'
urlpatterns = [
    path( '', views.IndexView.as_view(), name='index' ),
    # path( 'index/v2/', views.index_v2, name='index_v2' ),
    # path( 'index/v3/', views.index_v3, name='index_v3' ),
    path( '<int:pk>/', views.DetailView.as_view(), name='detail' ),
    # path( '<int:question_id>/detail/v2/', views.detail_v2, name='detail_v2' ),
    path( '<int:pk>/result/', views.ResultView.as_view(), name='result' ),
    path( '<int:question_id>/vote/', views.vote, name='vote' ),
]