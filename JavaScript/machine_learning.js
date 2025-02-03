const natural = require("natural");
const readlineSync = require("readline-sync");
const fs = require("fs");

// Initialize the tokenizer and classifier
const tokenizer = new natural.WordTokenizer();
const classifier = new natural.BayesClassifier();

// File paths
const trainingDataFile = "trainingData.json";

// Store user personal data
const userData = {};

// Load existing training data from file
function loadTrainingData() {
  if (fs.existsSync(trainingDataFile)) {
    const data = JSON.parse(fs.readFileSync(trainingDataFile, "utf8"));
    data.forEach((item) => {
      if (item.text && item.category) {
        if (Array.isArray(item.text)) {
          item.text.forEach((text) => {
            classifier.addDocument(tokenizer.tokenize(text), item.category);
          });
        } else {
          classifier.addDocument(tokenizer.tokenize(item.text), item.category);
        }
      } else {
        console.error("Invalid entry in training data:", item);
      }
    });
    classifier.train(); // Train the classifier after loading data
    console.log("Training data loaded and classifier trained.");
  } else {
    console.log("No existing training data found. Starting fresh.");
  }
}

// Handle user input for specific requests
function handleSpecialCases(userInput) {
  const lowerInput = userInput.toLowerCase();

  // Handle the user's name question
  if (lowerInput.includes("what is my name")) {
    if (userData.name) {
      return `Your name is ${userData.name}.`;
    } else {
      return "I don't know your name yet. You can tell me by saying 'My name is [your name]'.";
    }
  }

  // Handle the date question
  if (lowerInput.includes("what is today's date")) {
    return `Today's date is ${new Date().toLocaleDateString()}.`;
  }

  // Handle time question
  if (lowerInput.includes("what is the time")) {
    return `The current time is ${new Date().toLocaleTimeString()}.`;
  }

  return null; // Not a special case
}

// Get response based on user input
function getResponse(text) {
  const specialResponse = handleSpecialCases(text);
  if (specialResponse) {
    return specialResponse; // If it's a special case, return the specific response
  }

  const tokenizedText = tokenizer.tokenize(text);
  const category = classifier.classify(tokenizedText);
  const data = JSON.parse(fs.readFileSync(trainingDataFile, "utf8"));

  // Find a response based on category
  const responseEntry = data.find((entry) => entry.category === category);

  if (responseEntry) {
    // Replace placeholders with actual values
    return responseEntry.response
      .replace("{time}", new Date().toLocaleTimeString())
      .replace("{date}", new Date().toLocaleDateString())
      .replace("{name}", userData.name || "friend");
  } else {
    // Provide default response if no match is found
    return "I’m not sure how to respond to that. Can you ask something else?";
  }
}

// Handle personal name input
function handlePersonalName(userInput) {
  const nameRegex = /my name is ([\w\s]+)/i; // Updated regex to handle multi-word names
  const match = userInput.match(nameRegex);
  if (match) {
    userData.name = match[1].trim(); // Store user's name
    return `Got it! I'll remember your name is ${userData.name}.`;
  }
  return 'Can you tell me your name in the format "My name is [name]"?';
}

// Interactive chatbot session
function chat() {
  console.log('Chatbot is ready! Type "exit" to quit.');

  // Load training data on start
  loadTrainingData();

  while (true) {
    const userInput = readlineSync.question("You: ");

    if (userInput.toLowerCase() === "exit") {
      break;
    }

    if (/my name is/i.test(userInput)) {
      console.log(`Bot: ${handlePersonalName(userInput)}`);
      continue;
    }

    console.log(`Bot: ${getResponse(userInput)}`);
  }

  console.log("Goodbye!");
}

chat();
