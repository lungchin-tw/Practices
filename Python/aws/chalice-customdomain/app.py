from chalice import Chalice

app = Chalice(app_name='jacky-chen-chalice-customdomain')


@app.route('/')
def index():
    return {'hello': 'jacky-chen-chalice-customdomain'}
