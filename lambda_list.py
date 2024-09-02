'''Write a lambda expression that will add up all the values of 
 list with lambda expression.
'''

numbers = [1, 2, 3, 4, 5]

sum_of_numbers = sum(map(lambda x: x, numbers))

print("Sum of all values in the list:", sum_of_numbers)
