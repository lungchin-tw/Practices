# Author: Jacky


import sys
print( '\n{}\n'.format( sys.version ) )


class NumberCounter:
    Max = 20

    def __iter__(self):
        self.counter = 0
        return self

    def __next__(self):
        if self.counter < self.Max:
            old_value = self.counter
            self.counter += 1
            return old_value
        else:
            raise StopIteration


a_number_counter = NumberCounter()
it = iter(a_number_counter)

for number in it:
    print( number )

        