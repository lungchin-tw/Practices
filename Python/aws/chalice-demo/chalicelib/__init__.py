
import sys

APP_NAME='jacky-chalice-demo'

def func_desc(cls) -> str:
    frame = sys._getframe(1)
    if cls is None:
        return f'{frame.f_code.co_name}, {frame.f_code.co_filename}:{frame.f_lineno}'
    else:
        return f'{cls}:{frame.f_code.co_name}, {frame.f_code.co_filename}:{frame.f_lineno}'
