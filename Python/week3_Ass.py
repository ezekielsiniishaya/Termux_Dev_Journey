#Function to calculate discount to a price and print new price
def calculate_discount(price, discount_percent):
    if (discount_percent >= 20):
        new_price = price - price * (discount_percent/100)
        print("Discounted Price: ", new_price)
    else:
        print("Prince: ", price)
#Receiving the price and discount from user, converting to float since by default, input converts to string
price = float(input("Enter the Prince: "))
discount_percent = float(input("Enter the discount: "))
#calling the function
calculate_discount(price, discount_percent)
