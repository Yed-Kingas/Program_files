def cal_ci(p,n,r,q):
    
    a=p*(1+r/q)**(n*q)
    ci=a-p
    return ci

p=int(input("Enter the Principal amount :"))
n=int(input("Enter the no of yrs :"))
r=int(input("Enter the rate of interest :"))
q=int(input("Enter the no of times the interest is compounded per yr :"))
i=cal_ci(p, n, r, q)
print("The compound interest is", round(i,2))