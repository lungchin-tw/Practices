
list_of_months = ['January', 'February', 'March', 'February']
print(f'Type of months:{type(list_of_months)}, Length:{len(list_of_months)}, Value:{list_of_months}')

set_of_months = set(list_of_months)
print(f'Type of set(months):{type(set_of_months)}, Length:{len(set_of_months)}, Value:{set_of_months}')

set_of_day = {'Monday', 'Tuesday', 'Wednesday', 'Thursday'}
for day in set_of_day:
    print(day)

set_of_day.add('Sunday')
print(f'Set of Day:{set_of_day}')
set_of_day.remove('Monday')
print(f'Set of Day:{set_of_day}')