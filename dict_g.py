# Define the dictionary for prices
prices = {
    "apple": 2,
    "banana": 1,
   
}

quantities = {
    "apple": 1,
    "banana": 1,
    
}

total_bill = 0.0

for item, quantity in quantities.items():
    total_bill += prices[item] * quantity

print("Total bill:", total_bill)



# Define the dictionary for prices
# prices = {
#     "apple": 2,
#     "banana": 2,
#     "orange": 1,
#     "milk": 1,
#     "bread": 1
# }

# quantities = {
#     "apple": 1,
#     "banana": 2,
#     "orange": 1,
#     "milk": 2,
#     "bread": 1
# }

# total_bill = 0.0
# bill_details = []

# for item, quantity in quantities.items():
#     item_cost = prices[item] * quantity
#     total_bill += item_cost
#     bill_details.append(f"{item.capitalize()}: {quantity} * {prices[item]} = {item_cost}")

# bill_details.append(f"\nTotal bill: ₹ {total_bill}")
# print("\n".join(bill_details))
# print(dir(dict))
# print(type(dict.join))
