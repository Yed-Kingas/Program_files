'''Write a program that will add elements of two list with map () and function. 
List1=[1,2,3,4,5,6], List2=[5,6,7,8,9,2]
'''

list1 = [1, 2, 3, 4, 5, 6]
list2 = [5, 6, 7, 8, 9, 2]


r=list(map(lambda x,y:x+y,list1,list2))
print("The result is :",r)