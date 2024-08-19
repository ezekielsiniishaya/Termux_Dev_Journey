function roundTo(n, step = 1) {let
remainder = n % step;
return n - remainder + (remainder < step / 2 ? 0 : step);
};
console.log(roundTo(5.2));

console.log(roundTo(5.2, 2));
