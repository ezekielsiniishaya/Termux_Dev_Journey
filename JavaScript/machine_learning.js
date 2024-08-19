
const natural = require('natural');
const readlineSync = require('readline-sync');
const fs = require('fs');

// Initialize the tokenizer and classifier
const tokenizer = new natural.WordTokenizer();
const classifier = new natural.BayesClassifier();

// File paths
const trainingDataFile = 'trainingData.json';

// Load existing training data from file
function loadTrainingData() {
  if (fs.existsSync(trainingDataFile)) {
    const data = JSON.parse(fs.readFileSync(trainingDataFile, 'utf8'));
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
        console.error('Invalid entry in training data:', item);
      }
    });
    classifier.train();
    console.log('Training data loaded from file.');
  } else {
    console.log('No existing training data found. Starting fresh.');
  }
}

// Get response based on user input
async function getResponse(text) {
  const category = classifier.classify(tokenizer.tokenize(text));
  const data = JSON.parse(fs.readFileSync(trainingDataFile, 'utf8'));

  // Find a response based on category
  const responseEntry = data.find((entry) => entry.category === category);

  if (responseEntry) {
    return responseEntry.response
      .replace('{time}', new Date().toLocaleTimeString())
      .replace('{date}', new Date().toLocaleDateString())
      .replace('{name}', userData.name || 'friend');
  } else {
    // Provide default response if no match is found
    return 'I’m not sure how to respond to that. Can you ask something else?';
  }
}

// Store user personal data
const userData = {};

//
function handlePersonalName(userInput) {
 const nameRegex = /my name is (\w+)/i;
const match = userInput.match(nameRegex);
  if (match) {
    userData.name = match[1];
    return `Got it! I'll remember your name is ${userData.name}.`;
  }
  return 'Can you tell me your name in the format "My name is [name]"?';
}

// Interactive chatbot session
async function chat() {
  console.log('Chatbot is ready! Type "exit" to quit.');

  // Load training data on start
  loadTrainingData();

  while (true) {
    const userInput = readlineSync.question('You: ');

    if (userInput.toLowerCase() === 'exit') {
      break;
    }

    if (/my name is/i.test(userInput)) {
      console.log(`Bot: ${handlePersonalName(userInput)}`);
      continue;
    }

    // Get response from the chatbot
    console.log(`Bot: ${await getResponse(userInput)}`);
  }

  console.log('Goodbye!');
}

chat();
