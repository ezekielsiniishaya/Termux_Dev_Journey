#include <stdio.h>

int main() {
  int arr[100];  // Array to store integers
  int count = 0; // Counter for the number of integers

  printf("Enter integers separated by spaces (press Enter to finish): ");

  // Read integers until Enter is pressed or the array is full
  while (scanf("%d", &arr[count]) == 1) {
    count++;
  }

  // Display the elements stored in the array
  printf("The elements in the array are:\n");
  for (int i = 0; i < count; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}
