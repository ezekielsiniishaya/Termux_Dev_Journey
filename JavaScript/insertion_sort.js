// This is a program that uses insertion sort to sort an array

// This fuction inserts a value in a particular position in an array when some conditions are met
var insert = function (array, rightIndex, value) {
  var i;

  for (i = rightIndex; i >= 0 && array[i] > value; i--) {
    array[i + 1] = array[i];
  }
  array[i + 1] = value;
};
// This function loops through the array inserting the current value in the right position in the sorted subarray
var insertionSort = function (array) {
  for (var i = 1; i < array.length; i++) {
    insert(array, i - 1, array[i]);
    console.log(array);
  }
};

var array = [3, 5, 7, 11, 13, 2, 9, 6];
console.log(JSON.stringify(array));
insertionSort(array);
console.log(JSON.stringify(array));
