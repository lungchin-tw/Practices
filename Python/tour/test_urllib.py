
from core import *
import sys

logger = getLogger(__name__)
logger.info(f'Loading {__file__}, \
            __name__:{__name__}, \
            sys.version: {sys.version}')


from urllib import request

rsp = request.urlopen('https://www.wikipedia.org')

logger.info(f'Type(Response): {type(rsp)}')
logger.info(f'Response.Code: {rsp.code}')
logger.info(f'Response.Length: {rsp.length}')
logger.info(f'Response.peek(): {rsp.peek()}')
logger.info(f'Response.isclosed(): {rsp.isclosed()}')