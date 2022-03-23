
units_a_day = {
    'hour': 24,
    'minute': 24 * 60,
    'second': 24 * 60 * 60,
}

print(f'Type of units_a_day: {type(units_a_day)}')

def stringify_days_to_units(num_of_days, unit):
    val = units_a_day[unit]
    result = num_of_days * val
    return f'{num_of_days} days are {result} {unit}s.'


def validate(val):
    try:
        num_of_days = int(val)
        print(f'Type of days: {type(num_of_days)}')
        if num_of_days <= 0:
            print(f'Invalid num_of_days: {num_of_days}')
            return False
        else:
            return True
    except Exception as e:
        print(f'Invalid input: {val}, Error: {e}')
        return False


def execute(val, unit):
    print(stringify_days_to_units(int(val), unit))


def is_quit_command(val):
    cmds = ['q', 'quit', 'exit']
    for elem in cmds:
        if val == elem:
            return True
    return False


while True:
    args = input("Enter [days:unit] ->\n").split(':')
    is_quit = is_quit_command(args[0])
    print(f'Type(is_quit): {type(is_quit)}; Value: {is_quit}')
    if is_quit:
        break
    elif validate(args[0]) == True:
        execute(args[0], args[1])
