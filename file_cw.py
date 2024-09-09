"""Write a program that will create file and write the
 following text in a file.
“Hello world. I am writing in the file now”"""

f=open("example.txt","w")
a="Hello world. I am writing in the file now"
f.write(a)
f.close()
try:
    f1=open("example.txt","r")
    a=f1.read()
    print(a)
    f1.close()
except FileNotFoundError as e:
    print(e)


