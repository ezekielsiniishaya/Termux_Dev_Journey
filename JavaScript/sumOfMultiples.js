// Import the readline module to receive user input
const readline = require("readline");

// Create an interface to read input from the command line
const rl = readline.createInterface({
  input: process.stdin, // Set up input stream (keyboard input)
  output: process.stdout, // Set up output stream (command line output)
});

// Prompt the user to enter a positive integer
rl.question("Input a positive integer: ", (n) => {
  // Close the readline interface once the input is received
  rl.close();

  let i; // Variable to iterate through numbers
  let multiple = 0; // Variable to store multiples of 3 or 5
  let sum = 0; // Variable to accumulate the sum of multiples

  // Loop through numbers starting from 0 up to (but not including) the user input 'n'
  for (i = 0; i < n; i++) {
    // Check if the current number is divisible by 3 or 5
    if (i % 3 == 0 || i % 5 == 0) {
      multiple = i; // If divisible, assign the number to 'multiple'
      sum += multiple; // Add the multiple to the sum
    }
  }

  // Output the sum of all multiples of 3 or 5 less than 'n'
  console.log(sum);
});
