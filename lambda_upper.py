'''Write a program that will accept a string in lower case and 
convert it into uppercase with lambda expression'''

input_string = input("Enter a string in lowercase: ")


uppercase_string = lambda s: s.upper()


print("Uppercase string:", uppercase_string(input_string))
