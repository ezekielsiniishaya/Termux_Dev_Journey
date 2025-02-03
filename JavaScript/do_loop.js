const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

function askQuestion() {
  return new Promise((resolve) => {
    rl.question('Who are you? ', (answer) => {
      resolve(answer);
    });
  });
}

async function main() {
  let answer;
  do {
    answer = await askQuestion();
  } while (!answer);

  console.log('Hello ' + answer);
  rl.close();
}

main();

