import spacy
import random
import json
from datetime import datetime

# Load the spaCy model
nlp = spacy.load("en_core_web_sm")

# Store user data
userData = {}

# Load training data
def load_training_data(file):
    with open(file, "r", encoding="utf-8") as f:
        return json.load(f)

# Handle special cases
def handle_special_cases(text):
    doc = nlp(text.lower())

    # Handle the user's name
    if "what is my name" in text.lower():
        if userData.get("name"):
            return f"Your name is {userData['name']}."
        else:
            return "I don't know your name yet. You can tell me by saying 'My name is [your name]'."

    # Handle date and time
    if "date" in text.lower():
        return f"Today's date is {datetime.now().strftime('%Y-%m-%d')}."
    if "time" in text.lower():
        return f"The current time is {datetime.now().strftime('%H:%M:%S')}."

    return None

# Handle personal name input
def handle_personal_name(text):
    if "my name is" in text.lower():
        doc = nlp(text)
        # Extract the person's name
        for ent in doc.ents:
            if ent.label_ == "PERSON":
                userData["name"] = ent.text
                return f"Got it! I'll remember your name is {userData['name']}."
    return 'Can you tell me your name in the format "My name is [name]"?'

# Classify user intent based on rules or training data
def classify_intent(text, training_data):
    for entry in training_data:
        for phrase in entry["text"]:
            if phrase in text.lower():
                return entry["category"], entry["response"]

    return "unknown", "I'm not sure how to respond to that. Can you ask something else?"

# Chatbot interaction
def chat(training_data_file):
    print("Chatbot is ready! Type 'exit' to quit.")
    
    # Load training data
    training_data = load_training_data(training_data_file)

    while True:
        user_input = input("You: ")

        if user_input.lower() == "exit":
            break

        # Handle personal name input
        if "my name is" in user_input.lower():
            response = handle_personal_name(user_input)
            print(f"Bot: {response}")
            continue

        # Handle special cases like name, date, time
        special_response = handle_special_cases(user_input)
        if special_response:
            print(f"Bot: {special_response}")
            continue

        # Classify intent based on the training data
        category, response = classify_intent(user_input, training_data)
        if "{name}" in response and not userData.get("name"):
            response = response.replace("{name}", "friend")
        elif "{name}" in response:
            response = response.replace("{name}", userData["name"])

        # Output the response
        print(f"Bot: {response}")

    print("Goodbye!")

# Call the chat function and pass the path to your training data
chat("trainingData.json")
