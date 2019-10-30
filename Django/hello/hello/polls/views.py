from inspect import currentframe, getframeinfo

from django.http import Http404, HttpResponse
from django.shortcuts import render, get_object_or_404
from django.template import loader

from .models import Question


def index(request):
    latest_question_list = Question.objects.order_by( '-pub_date' )[:1]
    context = '<br/>'.join( (q.question_text for q in latest_question_list) )

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

    result = '{} <br/><br/> Debug Verbose:{}'.format( context, msg )

    print( result )
    return HttpResponse( result )


def index_v2(request):
    latest_question_list = Question.objects.order_by( '-pub_date' )[:2]
    template = loader.get_template( 'polls/index.html' )
    context = { 'latest_question_list': latest_question_list }

    print( latest_question_list )
    print( template )
    print( context )

    return HttpResponse( template.render( context, request ) )


def index_v3(request):
    latest_question_list = Question.objects.order_by( '-pub_date' )[:3]
    context = { 'latest_question_list': latest_question_list }
    return render( request, 'polls/index.html', context )


def detail(request, question_id):
    try:
        q = Question.objects.get( pk=question_id )
    except Question.DoesNotExist:
        raise Http404( 'Question %s does not exist.' % question_id )

    return render( request, 'polls/detail.html', { 'question': q } )


def detail_v2(request, question_id):
    q = get_object_or_404( Question, pk=question_id )
    return render( request, 'polls/detail.html', { 'question': q } )


def result(request, question_id):
    return HttpResponse( 'You\'re looking at the result of question %s.' % question_id )


def vote(request, question_id):
    return HttpResponse( 'You\'re voting on question %s.' % question_id )
