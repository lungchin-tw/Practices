
def is_quit_command(val):
    cmds = ['q', 'quit', 'exit']
    for elem in cmds:
        if val == elem:
            return True
    return False


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