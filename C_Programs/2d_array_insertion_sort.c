#include <stdio.h>

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

    // Print array after each pass (optional)
    printf("After pass %d: ", i);
    for (int r = 0; r < rows; r++) {
      printf("{%d, %d} ", arr[r][0], arr[r][1]);
    }
    printf("\n");
  }
}

int main() {
  int arr[][2] = {{3, 4}, {5, 9}, {2, 3}, {1, 4}};
  int rows = sizeof(arr) / sizeof(arr[0]);
  int cols = sizeof(arr[0]) / sizeof(arr[0][0]);

  printf("Original array: ");
  for (int i = 0; i < rows; i++) {
    printf("{%d, %d} ", arr[i][0], arr[i][1]);
  }
  printf("\n\n");

  insertionSort2D(arr, rows, cols);

  printf("\nSorted array: ");
  for (int i = 0; i < rows; i++) {
    printf("{%d, %d} ", arr[i][0], arr[i][1]);
  }
  printf("\n");

  return 0;
}
