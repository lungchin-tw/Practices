
seconds_an_hour = 60 * 60
seconds_a_day = 24 * seconds_an_hour
name_of_unit = 'seconds'


def stringify_days_to_seconds(num_of_days): 
    result = num_of_days * seconds_a_day
    return f'{num_of_days} days are {result} {name_of_unit}.'


days = int(input("Enter a number of days:\n"))
print(stringify_days_to_seconds(days))