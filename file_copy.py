"""Copy the content of that file to another file 
after changing the text into uppercase."""

file1 = open("example.txt","r")
file2 = open("uppercase_file.txt","w")
content = file1.read().upper()
file2.write(content)
file2.close()
file2 = open("uppercase_file.txt","r")
b=file2.read()
print(b)

