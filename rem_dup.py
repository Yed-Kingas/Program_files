'''Write a program that defines a function 
remove_duplicate() to remove all duplicate entries from the list that it received.'''

def remove_duplicate(l):
    return list(set(l))
a=[1,1,2,2,3,3,4,4]
print(remove_duplicate(a))