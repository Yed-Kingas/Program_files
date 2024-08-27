# Define the dictionary for prices
prices = {
    "apple": 1,
    "banana": 1,
    "orange": 1,
    "milk": 1,
    "bread": 1
}


quantities = {
    "apple": 2,
    "banana": 1,
    "orange": 1,
    "milk": 1,
    "bread": 1
}


total_bill = 0.0


for item, quantity in quantities.items():
   
    total_bill += prices[item] * quantity
   


print("Total bill:", total_bill)
