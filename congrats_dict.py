"""Suppose a dictionary contains roll number and names of students. 
Write a program to receive the roll number and display a message congratulations the student by his name.
 If the roll number doesnt exit in the dictionary the message should be Congratulations Student."""

a={1:"Amal",2:"Bimal"}
b=int(input("Enter a roll number: "))
if b in a:
    print("Congrats",a[b])
else :
    print("Congrats Student")