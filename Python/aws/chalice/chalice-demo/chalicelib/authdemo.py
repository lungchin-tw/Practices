

from chalice import (
    Blueprint,
    Response,
    IAMAuthorizer,
    CognitoUserPoolAuthorizer,
    CustomAuthorizer,
    AuthResponse,
)

from . import func_desc
import logging

logger = logging.getLogger(__name__)
logger.setLevel(logging.DEBUG)

logger.info(f'Loading {__file__}, __name__:{__name__}')

BpAuth = Blueprint(__name__)

auth_iam=IAMAuthorizer()
@BpAuth.route('/auth/iam', methods=['GET'], authorizer=auth_iam)
def auth_iam():
    logger.info(func_desc())
    return Response(
        status_code=200,
        body={
            'app':BpAuth.current_app.app_name,
            'desc': func_desc()
        }
    )


auth_cognito=CognitoUserPoolAuthorizer(
    'RyanTest',
    provider_arns=['arn:aws:cognito-idp:eu-central-1:422686820116:userpool/eu-central-1_1TBe0wlST'],
)
@BpAuth.route('/auth/cognito', methods=['GET'], authorizer=auth_cognito)
def auth_cognito():
    logger.info(func_desc())
    return Response(
        status_code=200,
        body={
            'desc': func_desc()
        }
    )


@BpAuth.authorizer()
def demo_authorizer(auth_request) -> AuthResponse:
    logger.info(func_desc())
    token = auth_request.token
    if token == 'allow':
        return AuthResponse(
            routes=['/auth/authorizer'],
            principal_id='user',
        )
    else:
        return AuthResponse( routes=[], principal_id='user' )


@BpAuth.route('/auth/authorizer', authorizer=demo_authorizer)
def auth_authorizer() -> Response:
    logger.info(func_desc())
    return Response(
        status_code=200,
        body={
            'desc': func_desc(),
            'context': BpAuth.current_app.current_request.context,
        }
    )