

# class declaration, (object) could be omitted
class DemoClass(object):

    _counter = 0 # class variable

    # instance method
    def instance_method(self):
        print('instance method')

    # static method
    def static_method() -> str:
        return f'this is a static method:{ DemoClass._counter = }'

    @classmethod # class method
    def getCounter(cls):
        print(f'getCounter, cls:{cls}')
        return cls._counter


    @property # instance property
    def name(self):
        return self._name

    @name.setter
    def name(self, value):
        self._name = value


    # dunder/magic methods
    def __new__(cls, name):
        print(f'__new__({name}), cls:{cls}')
        return super().__new__(cls)
        

    def __init__(self, name):
        print(f'__init__({name}), self:{self}')
        self._name = name # instance variable
        self.__class__._counter += 1 # class variable


    

    







