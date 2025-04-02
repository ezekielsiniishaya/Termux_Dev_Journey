// Program to find the second largest number in an array

#include <stdio.h>

// Function to return the second largest number
int second_largest_number(int arr[], int n) {
  int largest = arr[-1];
  for (int i = 0; i < n; i++) {
    if (arr[i] > largest) {
      largest = arr[i]; // Finds the largest number
    }
  }
  int second_largest = 0;
  for (int j = 0; j < n; j++) {

    if (arr[j] >= second_largest && arr[j] < largest) {
      second_largest = arr[j]; // Finds the second largest number
    }
  }
  return second_largest;
}

int main() {
  int arr[] = {10, 10, 10, 10, 5};
  int n = 6;
  int second_largest = second_largest_number(arr, n);
  printf("Second largest number: %d\n", second_largest);
  return 0;
}
