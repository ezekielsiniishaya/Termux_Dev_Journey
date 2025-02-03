# Task 1: Accept user input to create a list of integers and compute the sum

# Accept user input and split it into a list of strings
user_input = input("Enter a list of integers separated by spaces: ").split()

# Convert strings to integers
int_list = [int(num) for num in user_input]

# Compute the sum of the integers
total_sum = sum(int_list)

# Print the sum
print(f"The sum of the integers is: {total_sum}")

# Task 2: Create a tuple with book names and print each book on a separate line

# Tuple containing favorite book names
favorite_books = ("The Alchemist", "To Kill a Mockingbird", "1984", "The Great Gatsby", "Moby Dick")

# Print each book name on a separate line
for book in favorite_books:
    print(book)

# Task 3: Store information about a person in a dictionary

# Create an empty dictionary to store information
person_info = {}

# Ask for user input and store it in the dictionary
person_info['name'] = input("Enter your name: ")
person_info['age'] = int(input("Enter your age: "))  # Convert age to an integer
person_info['favorite_color'] = input("Enter your favorite color: ")

# Print the dictionary
print(person_info)

# Task 4: Create two sets of integers and find common elements

# Accept user input for two sets of integers
set1 = set(map(int, input("Enter integers for the first set, separated by spaces: ").split()))
set2 = set(map(int, input("Enter integers for the second set, separated by spaces: ").split()))

# Find the intersection (common elements) of both sets
common_elements = set1.intersection(set2)

# Print the common elements
print(f"Common elements in both sets: {common_elements}")

# Task 5: Create a list of words and filter those with an odd number of characters

# List of words
words = ["apple", "banana", "cherry", "date", "fig", "grape"]

# List comprehension to filter words with an odd number of characters
odd_length_words = [word for word in words if len(word) % 2 != 0]

# Print the list of words with odd lengths
print(f"Words with an odd number of characters: {odd_length_words}")
