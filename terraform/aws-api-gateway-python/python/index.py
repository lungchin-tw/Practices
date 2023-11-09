
import logging
logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)

def lambda_handler(event, context):
    logger.debug(f'[lambda_handler], Event:{event}')
    logger.debug(f'[lambda_handler], context:{context}')
    
    return {
        'message': 'Hello {} !'.format(event.get('key1', "None"))
    }