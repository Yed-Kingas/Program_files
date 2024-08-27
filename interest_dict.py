'''Write a function that will accept Principal=p, number of years=n, 
rate of interest=r from user and calculate simple interest.
'''

def calculate_simple_interest(principal, years, rate):
   
    rate_decimal = rate / 100
    

    interest = principal * rate_decimal * years
    
    return interest



principal = float(input("Enter the principal amount (P): "))
years = int(input("Enter the number of years (n): "))
rate = float(input("Enter the annual interest rate (r) in percentage: "))
    
   
interest = calculate_simple_interest(principal, years, rate)
    
 
print("The simple interest is:", round(interest,2))

