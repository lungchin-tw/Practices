
import json, sys
from typing import *

class User:
    def __init__(self, name, email, password, title ) -> None:
        self.name = name
        self.email = email
        self.password = password
        self.title = title

    def change_password(self, value):
        self.password = value

    def change_title(self, value) -> str:
        self.title = value

    def desc(self) -> str:
        return json.dumps(self.json(), indent=4)

    def json(self) -> dict:
        frame = sys._getframe()
        return {
                'method_desc': f'{__class__}:{frame.f_code.co_name}, {frame.f_code.co_filename}:{frame.f_lineno}',
                'name': self.name,
                'email': self.email,
                'password': self.password,
                'title': self.title
            }