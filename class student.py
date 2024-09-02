'''Create a class Student and member are name, roll. Initialize the member of class
 and display the value. Create suitable object implement the operation.'''

class Student:
   
    def __init__(self, name, roll):
        self.name = name
        self.roll = roll
        print("Init function called")
 
    def display(self):
        print("Student Name:", self.name, "Roll Number:", self.roll)


student1 = Student("Bimal", 1)
student1.display()
