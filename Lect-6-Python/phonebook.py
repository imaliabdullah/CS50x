people = [
    {'name': 'Carter', 'number':'+1-323-2343'},
    {'name': 'David', 'number': '+1-233-3234'},
    {'name': 'John', 'number': '+1-234-2343'},
]

name = input("Name: ")

for person in people:
    if person['name'] == name:
        number = person['number']
        print(f'Found {number}')
        break
else:
    print('Not Found')
