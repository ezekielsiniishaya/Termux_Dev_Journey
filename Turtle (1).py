import requests
from bs4 import BeautifulSoup

def extract_product_info(url):
"""
  This function extracts product information (title, price) from a given URL.

  Args:
      url: The URL of the product page (string).

  Returns:
      A dictionary containing product title and price (or None if extraction fails).
  """
try:
# Send a GET request to the URL and retrieve the response
response = requests.get(url)
response.raise_for_status() # Raise an exception for unsuccessful requests

# Parse the HTML content using BeautifulSoup
soup = BeautifulSoup(response.content, 'html.parser')

# Find elements containing product title and price (replace with specific selectors based on the website structure)
title_element = soup.find("h1", class_ = "product-name") # Customize selectors as needed
price_element = soup.find("span", class_ = "price") # Customize selectors as needed

# Extract title and price text (handle cases where elements may not be found)
title = title_element.text.strip() if title_element else None
price = price_element.text.strip() if price_element else None

return {
  "title": title, "price": price
}

except requests.exceptions.RequestException as e:
print(f"Error: An error occurred while fetching the URL: {
  e
}")
return None

def main():
# Example usage: Extract product info from a sample URL
url = "https://google.com" # Replace with the actual product URL
product_info = extract_product_info(url)

if product_info:
print(f"Product Title: {
  product_info['title']}")
print(f"Product Price: {
  product_info['price']}")
else :
print("Failed to extract product information.")

if __name__ == "__main__":
main()