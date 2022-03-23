
seconds_an_hour = 60 * 60
seconds_a_day = 24 * seconds_an_hour
name_of_unit = 'seconds'


def stringify_days_to_seconds(num_of_days):
    result = num_of_days * seconds_a_day
    return f'{num_of_days} days are {result} {name_of_unit}.'


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


def execute(val):
    print(stringify_days_to_seconds(int(val)))


def is_quit_command(val):
    cmds = ['q', 'quit', 'exit']
    for elem in cmds:
        if val == elem:
            return True
    return False


while True:
    val = input("Enter a number of days:\n")
    is_quit = is_quit_command(val)
    print(f'Type(is_quit): {type(is_quit)}; Value: {is_quit}')
    if is_quit:
        break
    elif validate(val) == True:
        execute(val)



