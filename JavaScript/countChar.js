const { count } = require("console"); // Import 'count' from the 'console' module (although 'count' is unused here)
const readline = require("readline"); // Import the 'readline' module to enable reading input from the console

// Create an interface to read from standard input
const rl = readline.createInterface({
  input: process.stdin, // Set the input stream to standard input (keyboard input)
  output: process.stdout, // Set the output stream to standard output (console)
});

// Ask the user for a string input
rl.question("Welcome to character count! Enter the string: ", (answer) => {
  // After receiving the string, ask the user for the character they want to count
  rl.question("Which character do you want to count: ", (char) => {
    rl.close(); // Close the readline interface after getting both inputs

    // Function to count occurrences of 'char' in the 'answer' string
    function countChar(answer, char) {
      let i = 0, // Initialize index i for looping through the string
        j = 0; // Initialize counter j to keep track of how many times 'char' occurs
      while (i < answer.length) {
        // Loop through each character in 'answer'
        if (answer[i] == char) {
          // If the character at index 'i' matches 'char'
          j++; // Increment the counter j
        }
        i++; // Move to the next character in the string
      }
      return j; // Return the final count of how many times 'char' appeared
    }

    // Output the result to the console with the count of 'char' in 'answer'
    console.log(`There are ${countChar(answer, char)} ${char} in ${answer}`);
  });
});
