
// Program to find the second largest number in an array

#include <stdio.h>

// Function to return the second largest number
void second_largest_number(int arr[], int n) {
  int largest = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > largest) {
      largest = arr[i]; // Finds the largest number
    }
  }
  // printf("largest number is %d\n", largest);
  int second_largest;
  int found = 0;
  for (int j = 0; j < n; j++) {
    if (arr[j] < largest) {
      second_largest = arr[j];
      for (int k = j; k < n; k++) {
        if (arr[k] > second_largest && arr[k] < largest) {
          second_largest = arr[k]; // Finds the second largest number
        }
      }
      printf("Second largest number: %d\n", second_largest);
      found = 1;
      break;
    }
  }
  if (found == 0) {
    printf("All numbers are the same\n");
  }
}

int main() {
  int arr[] = {-63, -63, -1, -2, -3};
  int n = 5;
  second_largest_number(arr, n);
  return 0;
}
