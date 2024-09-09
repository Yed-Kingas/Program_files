"""Write a program that will accept a string and count the number 
of words in a string.
"""
def count_words(string):
    words = string.split()
    return len(words)


s = input("Enter a string: ")
c = count_words(s)
print("Number of words in the string: ", c)
