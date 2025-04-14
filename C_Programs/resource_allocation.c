// This program finds out the minimum number of resources needed for a meeting
// based on the time interval of the meetings

#include <stdio.h>
// 1. Save the intervals in a 2D array
// 2. Swap the rows based on the start time, least start time comes first

// Function to swap two rows of a 2D array
void swapRows(int row1[], int row2[], int cols) {
  for (int i = 0; i < cols; i++) {
    int temp = row1[i];
    row1[i] = row2[i];
    row2[i] = temp;
  }
}

// Function to perform insertion sort on a 2D array based on first column
void insertionSort2D(int arr[][2], int rows, int cols) {
  for (int i = 1; i < rows; i++) {
    int j = i;
    // Compare with the first element of each row
    while (j > 0 && arr[j][0] < arr[j - 1][0]) {
      swapRows(arr[j], arr[j - 1], cols);
      j--;
    }
  }
}
int resource_allocation(int arr[][2], int rows, int cols) {
  int ind_res = 0;
  int shared_res = 0;
  // 3. Check if the start time pverlaps and increment meeting room needed based
  for (int i = 0; i < rows; i++) {
    if (arr[i][1] >= arr[i + 1][0]) {
      shared_res = 1;
	  ind_res = 1;
    } else {
      ind_res++;
    }
  }
  printf("shared: %d, individual: %d\n", shared_res, ind_res);
  return ind_res;
}
int main() {
  int arr[][2] = {{3, 4}, {5, 9}, {2, 3}, {1, 4}};
  int rows = sizeof(arr) / sizeof(arr[0]);
  int cols = sizeof(arr[0]) / sizeof(arr[0][0]);
  insertionSort2D(arr, rows, cols);
  int num_of_res = resource_allocation(arr, rows, cols);
  printf("Needed resources: %d\n", num_of_res);
  return 0;
}
// on the output of the Check
