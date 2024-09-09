#Write a program that will print an identity matrix.
n = int(input("Enter the size of matrix : "))

for i in range(n):
    for j in range(n):
        if i == j:
            print(1, end=" ")
        else:
            print(0, end=" ")
    print()  
