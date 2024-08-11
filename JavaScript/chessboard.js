//Program to print a chessboard of any width and height
let a = '#';
let b = ' ';
let x = '';
let y = '';

const readline = require('readline');

// function to receive user input

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Input width for chessboard: ', (width) =>        {
rl.question('Input height for chessboard: ', (height) =>{
    //converting chessboard specs to user input
    for (let i = 0; i < width; i++) {
        x = x + (a + b);
        y = y + (b + a);
      }
    if (!((height % 2) == 0)) {
          for (let a = 0; a < ((height - 1) / 2); a++) {
              console.log(x + '\n' + y);
          }
         console.log(x);
    }
    else {
        for (let j = 0;j < (height/2); j++) {
         console.log(x + '\n' + y);
        }
    }

rl.close();});
});
/* I was so excited completing this code. I decided not to uuse concepts beyond loops, such as arrays and it totally worked out perfectly. I had a lot of fund figuring out how to print my chessboard of a height not divisible by 2, since I used two separate variables to store 1 line and 2 line and then repeating those two, I always ended up with one extra line when my height is an odd number, but not anymore!!*/
