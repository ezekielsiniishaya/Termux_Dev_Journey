let a = "#";
let b = " ";
let x = "";
let y = "";

const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

rl.question("Input width for chessboard: ", (width) => {
  rl.question("Input height for chessboard: ", (height) => {
    rl.close();
    console.log("\n");

    // Create the alternating patterns for one row
    for (let i = 0; i < width; i++) {
      x += a + b;
      y += b + a;
    }

    // Adjust the number of rows printed based on odd or even height
    for (let j = 0; j < Math.floor(height / 2); j++) {
      console.log(x + "\n" + y);
    }

    // Print the extra row if height is odd
    if (height % 2 !== 0) {
      console.log(x);
    }

    console.log(`\n${width} X ${height} Chessboard`);
  });
});
