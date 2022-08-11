from chalice import Chalice

app = Chalice(app_name='jacky-chen-chalice-cd-demo')


@app.route('/')
def index():
    return {'hello': 'jacky-chen-chalice-cd-demo'}