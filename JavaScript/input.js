const readline = require("readline");

// Create an interface to read from standard input
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

// Ask a question
rl.question("Enter something: ", (answer) => {
  console.log(`You entered: ${answer}`);
  rl.close();
});
