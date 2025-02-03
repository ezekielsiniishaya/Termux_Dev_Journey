const readline = require("readline");

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

rl.question("How's the weather? ", (weather) => {
  rl.close();

  switch (weather) {
    case "rainy":
      console.log("Remember to bring an umbrella . ");
      break;
    case "sunny":
      console.log("Dress lightly . ");
    case "cloudy":
      console.log("Go outside . ");
      break;
    default:
      console.log("Unknown weather type!");
      break;
  }
});
