#include <stdio.h>

int main() {
  int arr[3][3] = {{10, 20, 30}, {40, 50, 60}, {70, 80, 90}};  // 2x3 array
  int rows = 3, cols = 3;
  int row_to_delete = 0;  // Row where the element is located
  int col_to_delete = 2;  // Column of the element to delete (30)

  // Shift elements to the left within the array
  for (int i = row_to_delete; i < rows; i++) {
    for (int j = (i == row_to_delete ? col_to_delete : 0); j < cols - 1; j++) {
      arr[i][j] = arr[i][j + 1];
    }
    // If not the last row, bring the first element of the next row to fill the
    // gap
    if (i < rows - 1) {
      arr[i][cols - 1] = arr[i + 1][0];
    }
  }

  // Handle the last column of the last row
  arr[rows - 1][cols - 1] = 0;  // Example placeholder for the "deleted" element

  // Print the updated array
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%d ", arr[i][j]);
    }
    putchar('\n');
  }

  return 0;
}
