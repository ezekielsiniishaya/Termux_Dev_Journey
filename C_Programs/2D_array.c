#include <stdio.h>

#define MAX_ROWS 5
#define MAX_COLUMNS 10

int main() {
  char array_2D[MAX_ROWS][MAX_COLUMNS];
  int row, column;

  printf("Enter %d lines of sentences (each line up to %d characters):\n", MAX_ROWS, MAX_COLUMNS - 1);

  for (row = 0; row < MAX_ROWS; row++) {
    printf("Line %d: ", row + 1);
    column = 0;
    while (column < MAX_COLUMNS - 1) {
      char character = getchar();
      if (character == '\n') {
        break;
      }
      array_2D[row][column++] = character;
    }
    array_2D[row][column] = '\0';  // Null-terminate the string
  }

  printf("\nYou entered:\n");
  for (row = 0; row < MAX_ROWS; row++) {
    column = 0;
    while (array_2D[row][column] != '\0') {
      putchar(array_2D[row][column]);
      column++;
    }
    putchar('\n');
  }

  return 0;
}
