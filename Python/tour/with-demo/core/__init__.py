
import sys

def func_desc(cls=None) -> str:
    frame = sys._getframe(1)
    if cls is None:
        return f'{frame.f_code.co_name}, {frame.f_code.co_filename}:{frame.f_lineno}'
    else:
        return f'{type(cls)}:{frame.f_code.co_name}, {frame.f_code.co_filename}:{frame.f_lineno}'
