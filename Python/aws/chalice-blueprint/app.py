from chalice import Chalice
from chalicelib.bpapi import bpapi
from chalicelib.bpevent import bpevent

print(f'Loading {__file__}')

app = Chalice(app_name='jacky-chen-chalice-blueprint', debug=True)
app.register_blueprint(bpapi, name_prefix='jacky-chen')
app.register_blueprint(bpevent, name_prefix='jacky-chen')

@app.route('/')
def index():
    return {'hello': 'world'}

app.log.info(f'{app.routes}')