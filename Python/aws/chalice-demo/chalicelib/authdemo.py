

from chalice import (
    Blueprint,
    Response,
    IAMAuthorizer,
    CognitoUserPoolAuthorizer,
    CustomAuthorizer,
    AuthResponse,
)

from . import func_desc

print(f'Loading {__file__}, __name__:{__name__}')

BpAuth = Blueprint(__name__)

auth_iam=IAMAuthorizer()
@BpAuth.route('/auth/iam', methods=['GET'], authorizer=auth_iam)
def auth_iam():
    print(func_desc())
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
    print(func_desc())
    return Response(
        status_code=200,
        body={
            'desc': func_desc()
        }
    )

# auth_custom=CustomAuthorizer(
#     'CustomAuth',
#     header='Authorization',
#     authorizer_uri=('arn:aws:apigateway:region:lambda:path/2015-03-31'
#                     '/functions/arn:aws:lambda:eu-central-1:422686820116:function:jacky-chen-chalice-demo-dev/invocations'))
# @BpAuth.route('auth/custom', methods=['GET'], authorizer=auth_custom)
# def auth_custom():
#     print(func_desc())
#     return Response(
#         status_code=200,
#         body={
#             'desc': func_desc()
#         }
#     )


# @BpAuth.lambda_function()
# def auth_lambda_func(event, context):
#     print(func_desc())
#     return Response(
#         status_code=200,
#         body={
#             'desc': func_desc(),
#             'event': f'{event}',
#         }
#     )


@BpAuth.authorizer()
def demo_authorizer(auth_request) -> AuthResponse:
    print(func_desc())
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
    print(func_desc())
    return Response(
        status_code=200,
        body={
            'desc': func_desc(),
            'context': BpAuth.current_app.current_request.context,
        }
    )