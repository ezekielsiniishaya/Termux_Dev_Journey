function findSolution(target) {
  // Inner function 'find' performs the recursive search.
  // It takes the current number and the history of operations used to reach it.
  function find(current, history) {
    // Base case: If the current number equals the target, return the history of operations.
    if (current == target) {
      return history;
    }
    // If the current number exceeds the target, return null (dead end).
    else if (current > target) {
      return null;
    }
    // Recursive case: Try adding 5 or multiplying by 3,
    // updating the history of operations as strings.
    else {
      // If one of the recursive calls returns a valid solution, it will be returned.
      // The '??' operator returns the first non-null result between the two options.
      return (
        find(current + 5, `(${history} + 5)`) ??
        find(current * 3, `(${history} * 3)`)
      );
    }
  }

  // Initial call starts the search from the number 1 with the history "1".
  return find(1, "1");
}

// Example of calling the function with the target number 24.
console.log(findSolution(13)); // Outputs the steps to reach 24 from 1, or null if impossible.
