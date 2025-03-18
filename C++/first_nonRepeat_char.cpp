/* This program returns the first non-repeating character from an array */
#include <cctype> // Include this for tolower()
#include <iostream>
using namespace std;

// Function to find and print the first non-repeating character
void first_nonRepeat_char(char arr[], int n) {
  // This array stores repeated characters
  char arr2[256] = {};
  // Stores the non-repeated character
  char non_repeat;
  // Variable to track if a character is arr2
  int found;
  // variable to track whether a non repeating character was found or not
  int copied;
  // Printing the enture array on the console
  cout << arr << endl;
  for (int i = 0; i < n; i++) {
    non_repeat = tolower(
        arr[i]); // coverta all letters to lowercase and setting the current element as the non-repeating character
    found = 0;
    copied = 0;
    for (int k = 0; k < n; k++) {
      if (arr2[k] == non_repeat) {
        found = 1; // Current character is in arr2
        copied = 1;
      }
    }
    if (found != 1) {
      for (int j = i + 1; j < n; j++) {
        if (arr[j] == non_repeat) {
          arr2[i] = arr[j]; // copying repeated character to arr2
          copied = 1;
        }
      }
    }
    // If current character is not in arr2 and not in arr  prunt it as the non-repeating character
    if (copied == 0) {
      cout << "First non repeating character is " << arr[i] << endl;
      break;
    }
  }
  // No non-repeating character in the array
  if (copied == 1) {
    cout << "All characters where repeated" << endl;
  }
}
int main() {
  char arr[] = {'A', 'a', 'B', 'b', 'C'};
  int n = sizeof(arr) / sizeof(arr[0]); // Calculates the length of arr
  first_nonRepeat_char(arr, n);
  return 0;
}
