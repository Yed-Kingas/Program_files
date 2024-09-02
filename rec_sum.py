'''Write a recursive function to obtain the running sum of first 25 natural numbers'''

def running_sum(n):
   
    if n == 1:
        return 1
    else:
      
        return n + running_sum(n - 1)


result = running_sum(25)
print("The running sum of the first 25 natural numbers is:", result)
