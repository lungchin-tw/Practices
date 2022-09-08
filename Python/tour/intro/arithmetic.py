
def max(*args):
    if len(args) < 1:
        raise Exception("Not enough arguments, at least 1.")

    max = args[0]
    if len(args) < 2:
        return max

    for v in args:
        if v > max:
            max = v

    return max


# print(max(1,29, -10))
# print(max())