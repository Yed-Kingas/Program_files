'''A positive number is entered through the keyboard, 
write a recursive function to calculate sum of digits of the 4-digit number.
'''

def sum_of_digits(n):

    if n == 0:
        return 0
    else:
       
        return n % 10 + sum_of_digits(n // 10)


number = int(input("Enter a 4-digit positive number: "))


if 1000 <= number <= 9999:

    print("Sum of digits is:", sum_of_digits(number))
else:
    print("Please enter a valid 4-digit positive number.")
