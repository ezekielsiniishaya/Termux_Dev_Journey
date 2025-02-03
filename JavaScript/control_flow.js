const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Pick a number: ', (answer) => {
  if (!isNaN(answer)) {
    console.log(`You picked the number ${Number(answer)}`);
  } else if (/[^a-zA-Z0-9]/.test(answer)) {
    console.log('You entered a special character.');
  } else {
    console.log('You entered a string.');
  }
  rl.close();
});

