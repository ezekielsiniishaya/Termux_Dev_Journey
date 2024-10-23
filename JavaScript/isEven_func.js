// Function to determine whether a number is even or not
function isEven(a) {
  // Base case: if the number is 0, it is considered even by definition
  if (a == 0) {
    return true;
    // Base case: if the number is 1, it is not even (it's odd)
  } else if (a == 1) {
    return false;
    // Base case: if the number is -1, it's also odd (just like 1)
  } else if (a == -1) {
    return false;
    // Recursive case: use the absolute value of 'a', subtract 2, and check again
  } else {
    // (a ** 2) ** 0.5 gives the absolute value of 'a'
    // Recursively call isEven with (absolute value of a - 2)
    return isEven((a ** 2) ** 0.5 - 2);
  }
}

// Testing the function with number -6
console.log(isEven(3)); // Output: true
