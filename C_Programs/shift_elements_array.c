#include <stdio.h>

int main() {
  int arr[] = {1, 2, 3};
  int size = 3;
  int valueToDelete = 1;

  // Find the index of the value to delete
  int index = -1;
  for (int i = 0; i < size; i++) {
    if (arr[i] == valueToDelete) {
      index = i;
      break;
    }
  }

  // If found, shift elements to the left
  if (index != -1) {
    for (int i = index; i < size - 1; i++) {
      arr[i] = arr[i + 1];
    }
    size--; // Reduce size since one element is removed
  }

  // Print updated array
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}
