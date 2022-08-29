
test = [v for v in range(1, 10, 2)]
print(f'test:{test}')

months = ['January', 'February', 'March']
print(months[1])

months.append('April')
months.extend(['May', 'June'])

print(f'Months:{months}, Len={len(months)}')
print(f'Months[1:5]:{months[1:5]}')
