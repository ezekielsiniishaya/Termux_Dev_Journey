function multiplier(factor) {
  return (number) => number * factor;
}
let twice = multiplier(2);
let thrice = multiplier(3);
console.log(`5 twicw is ${twice(5)}`);
console.log(`5 thrice is ${thrice(5)}`);
