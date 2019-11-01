from inspect import currentframe, getframeinfo

from django.http import Http404, HttpResponse, HttpResponseRedirect
from django.shortcuts import get_object_or_404, render
from django.template import loader
from django.urls import reverse
from django.views import generic

from .models import Question, Choice


class IndexView(generic.ListView):
    template_name = 'polls/index.html'
    context_object_name = 'latest_question_list'

    def get_queryset(self):
        return Question.objects.order_by('-pub_date')[:5]


class DetailView(generic.DetailView):
    model = Question
    template_name = 'polls/detail.html'


class ResultView(generic.DetailView):
    model = Question
    template_name = 'polls/result.html'


def print_request(request):
    print(
        '''
    Request:
        request: {}
        request.GET: {}
        request.POST: {}
        request.scheme: {}
        request.headers: {}
        '''.format(
            request,
            request.GET,
            request.POST,
            request.scheme,
            request.headers
        )
    )

    print( "request.body: %s\n" % request.body )


def print_frame_info( fi ):
    print( 
        '''
    Frame Info:
        doc:{}
        method:{}
        file:{}:{}
        name:{}
        package:{}
        '''.format(
            __doc__,
            fi.function,
            fi.filename,
            fi.lineno,
            __name__,
            __package__
        )
    )


def index(request):
    print_frame_info( getframeinfo(currentframe()) )
    print_request(request)

    latest_question_list = Question.objects.order_by( '-pub_date' )[:1]
    context = '<br/>'.join( (q.question_text for q in latest_question_list) )

    print( context )
    return HttpResponse( context )


def index_v2(request):
    print_frame_info( getframeinfo(currentframe()) )

    latest_question_list = Question.objects.order_by( '-pub_date' )[:2]
    template = loader.get_template( 'polls/index.html' )
    context = { 'latest_question_list': latest_question_list }

    print( latest_question_list )
    print( template )
    print( context )

    return HttpResponse( template.render( context, request ) )


def index_v3(request):
    print_frame_info( getframeinfo(currentframe()) )

    latest_question_list = Question.objects.order_by( '-pub_date' )[:3]
    context = { 'latest_question_list': latest_question_list }
    return render( request, 'polls/index.html', context )


def detail(request, question_id):
    print_frame_info( getframeinfo(currentframe()) )
    print_request(request)

    try:
        q = Question.objects.get( pk=question_id )
    except Question.DoesNotExist:
        raise Http404( 'Question %s does not exist.' % question_id )

    return render( request, 'polls/detail.html', { 'question': q } )


def detail_v2(request, question_id):
    print_frame_info( getframeinfo(currentframe()) )
    print_request(request)

    print( 'question_id: %d' % question_id )
    q = get_object_or_404( Question, pk=question_id )
    return render( request, 'polls/detail_v2.html', { 'question': q } )


def result(request, question_id):
    print_frame_info( getframeinfo(currentframe()) )
    print_request(request)

    print( 'question_id: %d' % question_id )
    return HttpResponse( 'You\'re looking at the result of question %s.' % question_id )


def vote(request, question_id):
    print_frame_info( getframeinfo(currentframe()) )
    print_request(request)

    print( 'question_id: %d' % question_id )

    q = get_object_or_404( Question, pk=question_id )

    try:
        selected_choice = q.choice_set.get(pk=request.POST['choice'])
    except (KeyError, Choice.DoesNotExist):
        context ={
            'question': q,
            'error_message': "Invalid Choice!!!"
        }

        return render(request, 'polls/detail_v2.html', context )
    else:
        selected_choice.votes += 1
        selected_choice.save()
        url = reverse( 'polls:result', args=( q.id, ) )
        print( 'url: %s' % url )
        return HttpResponseRedirect( url )
