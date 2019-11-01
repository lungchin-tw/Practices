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

        return render(request, 'polls/detail.html', context )
    else:
        selected_choice.votes += 1
        selected_choice.save()
        url = reverse( 'polls:result', args=( q.id, ) )
        print( 'url: %s' % url )
        return HttpResponseRedirect( url )
