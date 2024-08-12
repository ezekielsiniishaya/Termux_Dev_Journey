#Python lists Exercise
#Creating list
guests = ['Ishaya', 'Hajara', 'Patience', 'Ephraim', 'Enoch', 'Emmanuel', 'Mbursa', 'Elijah']
#Printing lists
i = 0
while i < 8:
        print(f'You are invited to my wedding, {guests[i]}.')
        i += 1
print(f'Unfortunately, {guests[3]} will not make it to the wedding')
#Replacing item in lists
guests[3] = 'Divine'
#Printing new lists
j = 0
while j < 8:
    print(f'You are invited to my wedding, {guests[j]}.')
    j += 1
#Adding items to lists using insert() and append()
print('Good news! There is more room to invite new people')
guests.insert(0, 'Godwin')
guests.insert(4, 'Faith')
guests.append('Success')
#Printing new lists
k = 0
while k < 11:
    print(f'You are invited to my wedding, {guests[k]}.')
    k += 1
print('Unfortunately, Dinner available is for only 2 people')
#Removing items from lists in batch, from end of lists until only first two remaining and printing the removed item as they are removed

l = 10
while l > 1:
    print(f'Sorry, {guests.pop(l)}, I have run out of space')
    l -= 1
#Printing the remaining two items in the lists
m = 0
while m < 2:
    print(f'You are still invited to my wedding, {guests[m]}.')
    m += 1
#deleting the remaining two items from the lists
del guests[0]
del guests[0]
#printing the lists after it has been emptied
print(guests)
