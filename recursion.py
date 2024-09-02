#Find out the factorial of a number through recursive function.

def rec(n):
    if n==0:
        return 1
    else:
        x=n*rec(n-1)
    return x

a=int(input("Enter a number : "))
b=rec(a)
print(b)
