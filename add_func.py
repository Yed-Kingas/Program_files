def cal_sum_prod(a,b,c):
    a1 =(a+b+c)
    b1= (a*b*c)
    return "Sum is", a1, "and Product is", b1
a=int(input("Enter a number :"))
b=int(input("Enter another number :"))
c=int(input("Enter last number :"))
q= cal_sum_prod(a,b,c)
print(q)
