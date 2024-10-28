def calculate_discount(price, discount_percent):
    if (discount_percent >= 20):
        new_price = price - price * (discount_percent/100)
        print("Discounted Price: ", new_price)
    else:
        print("Prince: ", price)

price = float(input("Enter the Prince: "))
#print(type(price))
discount_percent = float(input("Enter the discount: "))
#print(type(discount_percent))
calculate_discount(price, discount_percent)
