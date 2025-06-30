#include <stdio.h>

void swapRows(int row1[], int row2[], int cols) {
  for (int i = 0; i < cols; i++) {
    int temp = row1[i];
    row1[i] = row2[i];
    row2[i] = temp;
  }
}

void insertionSort2D(int arr[][2], int rows, int cols) {
  for (int i = 1; i < rows; i++) {
    int j = i;
    while (j > 0 && arr[j][0] < arr[j - 1][0]) {
      swapRows(arr[j], arr[j - 1], cols);
      j--;
    }
  }
}

int resource_allocation(int arr[][2], int rows, int cols) {
  insertionSort2D(arr, rows, cols);

  int active_end_times[rows];
  int size = 0, max_rooms = 0;

  for (int i = 0; i < rows; i++) {
    int start = arr[i][0];
    int end = arr[i][1];

    // Remove all ended meetings
    int new_size = 0;
    for (int j = 0; j < size; j++) {
      if (active_end_times[j] > start) {
        active_end_times[new_size++] = active_end_times[j];
      }
    }

    // Add current meeting
    active_end_times[new_size++] = end;
    size = new_size;

    if (size > max_rooms) {
      max_rooms = size;
    }
  }

  return max_rooms;
}

int main() {
  int arr[][2] = {{3, 4},   {3, 9}, {2, 3}, {1, 2}, {7, 10},
                  {10, 12}, {6, 9}, {1, 4}, {5, 8}};
  int rows = sizeof(arr) / sizeof(arr[0]);
  int cols = sizeof(arr[0]) / sizeof(arr[0][0]);

  int num = resource_allocation(arr, rows, cols);
  printf("Minimum rooms needed: %d\n", num);
  return 0;
}
