s = input('Do you agree? ')

if s.lower() in ['y', 'yes']:
    print('Agreed')
elif s.lower() in ['n', 'no']:
    print('Not Agreed')
else:
    continue
