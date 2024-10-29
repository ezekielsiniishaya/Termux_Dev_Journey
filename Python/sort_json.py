import json

# Define the path to your JSON file
file_path = 'data.json'

# Load the JSON data from the file
with open(file_path, 'r') as file:
    data = json.load(file)

# Sort the data by keys in alphabetical order
sorted_data = dict(sorted(data.items()))

# Print the sorted data (optional)
#print(json.dumps(sorted_data, indent=4))

# Save the sorted data back to the file (optional)
with open(file_path, 'w') as file:
    json.dump(sorted_data, file, indent=4)
