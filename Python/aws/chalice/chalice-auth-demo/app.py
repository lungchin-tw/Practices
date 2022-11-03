from chalice import Chalice

app = Chalice(app_name='jacky-auth-demo')


@app.route('/')
def index():
    return {'hello': 'world'}


from chalice import IAMAuthorizer
iam_auth = IAMAuthorizer()

@app.route('/iam-auth', methods=['GET'], authorizer=iam_auth)
def iam():
    return {'hello': 'iam'}
