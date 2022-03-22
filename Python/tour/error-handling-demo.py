
seconds_an_hour = 60 * 60
seconds_a_day = 24 * seconds_an_hour
name_of_unit = 'seconds'


def stringify_days_to_seconds(num_of_days):
    result = num_of_days * seconds_a_day
    return f'{num_of_days} days are {result} {name_of_unit}.'


def validate_and_execute(val):
    try:
        num_of_days = int(val)
        print(f'Type of days: {type(num_of_days)}')
        if num_of_days <= 0:
            print(f'Invalid num_of_days: {num_of_days}')
        else:
            print(stringify_days_to_seconds(num_of_days))
    except Exception as e:
        print(f'Invalid input: {val}, Error: {e}')


validate_and_execute(input("Enter a number of days:\n"))


