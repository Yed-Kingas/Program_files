#Write a program that will add 3 numbers with lambda expression

a1=int(input("Enter a number : "))
a2=int(input("Enter a number : "))
a3=int(input("Enter a number : "))
print((lambda a,b,c : a+b+c)(a1,a2,a3))