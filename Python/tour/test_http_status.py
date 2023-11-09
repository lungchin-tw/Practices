
from http import HTTPStatus

print(f'type(HTTPStatus.OK):{type(HTTPStatus.OK)}')
print(f'HTTPStatus.OK:{HTTPStatus.OK}')

x:int = 200
assert x == HTTPStatus.OK
print(f'x == HTTPStatus.OK:{x == HTTPStatus.OK}')