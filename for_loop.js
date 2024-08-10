const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function askQuestion() {
  rl.question('Who are you? ', (answer) => {
    if (!answer) {
      console.log('Please enter a valid name.');
      askQuestion(); // Ask again if no name was provided
    } else {
      console.log('Hello ' + answer);
      rl.close();
    }
  });
}

askQuestion();
