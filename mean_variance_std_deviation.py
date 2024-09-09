"""Write a program that will find out the mean and variance 
and standard deviation of 10 numbers.
 Numbers are [1,20,30,2,99,34,3,6,20,10].
"""
numbers = [1, 20, 30, 2, 99, 34, 3, 6, 20, 10]


n = len(numbers)
mean = sum(numbers) / n

variance_sum = sum((x - mean) ** 2 for x in numbers)
variance = variance_sum / n

std_deviation = variance ** 0.5

print("Mean: ", mean)
print("Variance: ", variance)
print("Standard Deviation: ", std_deviation)
