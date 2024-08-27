'''Suppose there are two dictionaries called boys and girls containing names as keys and ages as values.
 Write a program to merge the tow dictionaries into a third dictionaries.'''

boys={"Amal":5,"Bimal":2}
girls={"Vina":7,"Gita":1}
c={}

for i in (boys,girls):
    c.update(i)
print(c)