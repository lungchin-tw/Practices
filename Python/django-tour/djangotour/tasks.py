try: 
    from uwsgidecorators import timer
    import datetime
except ImportError:
    UWSGI_ENABLED = False
    uwsgi = uwsgidecorators = None
else:
    UWSGI_ENABLED = True

if UWSGI_ENABLED == True:
    @timer(10)
    def periodic_task_01(singal: int):
        print(f'{__name__}.periodic_task_01, Signal:{singal}, Time:{datetime.datetime.now()}')

    @timer(10)
    def periodic_task_02(singal: int):
        print(f'{__name__}.periodic_task_02, Signal:{singal}, Time:{datetime.datetime.now()}')
    

