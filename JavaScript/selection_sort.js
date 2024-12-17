// This is a program that sorts an array in accending order.

// 1. Create an array
var array = [8, 4, 6, 19, 3, 22, 14, 1];

// 2. Create a function, indexOfMinimum that returns the index of the minimum value in an array
console.log(JSON.stringify(array));

var indexOfMinimum = function (array, startIndex) {
  var minIndex = startIndex;
  var minValue = array[startIndex];
  for (var i = minIndex + 1; i < array.length; i++) {
    if (array[i] < array[minIndex]) {
      minIndex = i;
      minValue = array[i];
    }
  }
  return minIndex;
};

//console.log(
`Minimum index of the array [${array}] is ${indexOfMinimum(array, 0)}`;
//);
// 3. Create a function, swap that swaps the minimum values with the 0, 1, 2 and so on
var swap = function (array, firstIndex, secondIndex) {
  // Temporarily storing the value on at the first index before replacing it with the value at the second index
  var temp = array[firstIndex];

  // The swapping logic
  array[firstIndex] = array[secondIndex];
  array[secondIndex] = temp;
};

// 4. Create a function, selectionSort that finds the index of the minimum value and swaps it with the 0th index an so on.

var selectionSort = function (array) {
  for (var i = 0; i < array.length; i++) {
    minIndex = indexOfMinimum(array, i);
    swap(array, i, minIndex);
  }
};
// 5. Sort and print and array
selectionSort(array);
console.log(JSON.stringify(array));
var array2 = [0, 9, 8, 7, 6, 5, 4, 3, 2, 1];
console.log(JSON.stringify(array2));
selectionSort(array2);
console.log(JSON.stringify(array2));
