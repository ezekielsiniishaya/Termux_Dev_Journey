#A simple Python dictionary
import json  # Import the JSON module for handling JSON data

file_path = "data.json"  # Define the path to the JSON file containing the dictionary data
print("Welcome to the Dictionary. Type 'exit' to close.")  # Display welcome message

# Start an infinite loop to allow continuous searching
while True:
    keyword = input("Enter word to find the meaning: ").strip()  # Prompt user for a word and remove any extra spaces
    with open(file_path, 'r') as file:  # Open the JSON file in read mode
        data = json.load(file)  # Load the contents of the JSON file into a Python dictionary
        
        # Check if the entered keyword exists in the dictionary
        if keyword in data:
            print(f"{keyword}: {data[keyword][0]}")  # Print the meaning of the keyword

        else:
            start = True  # Initialize a flag to track if suggestions are being displayed
            # Iterate over all words and meanings in the dictionary
            for word, meaning in data.items():
                # Check if the word starts with the entered keyword (case insensitive)
                if word.lower().startswith(keyword):
                    if start:  # If this is the first match
                        print("Did you mean to search the word:")  # Prompt user with suggestion
                        start = False  # Update flag to indicate suggestions have started
                    print(word)  # Print the matching word
            
            print(f"The word '{keyword}' was not found")  # Inform user that the keyword was not found

    if keyword.lower() == 'exit':  # Check if the user wants to exit the program
        break  # Break the loop to exit the program
