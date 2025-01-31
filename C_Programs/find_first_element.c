#include <stdio.h>

#define MAX_ROWS 1000
#define MAX_COLUMNS 1000

// Function to find the first non-whitespace character in a row
int find_first_element(char array[][MAX_COLUMNS], int row) {
  int column = 0;
  while (array[row][column] != '\0') {
    if (array[row][column] != ' ' && array[row][column] != '\t') {
      return array[row][column];  // Return first non-whitespace character
    }
    column++;
  }
  return -1;  // No valid character found
}

int main() {
  char array_2D[MAX_ROWS][MAX_COLUMNS];  // Use char instead of int for text storage
  int row, column;
  int exit_status = 0;

  printf(
      "Enter up to %d lines of code (each line up to %d characters). Press "
      "Ctrl+D to stop:\n",
      MAX_ROWS, MAX_COLUMNS - 1);

  for (row = 0; row < MAX_ROWS; row++) {
    column = 0;
    while (column < MAX_COLUMNS - 1) {
      int character = getchar();
      if (character == EOF) {
        exit_status = 1;
        break;
      }
      if (character == '\n') {
        break;
      }
      array_2D[row][column++] = (char)character;
    }
    array_2D[row][column] = '\0';  // Null-terminate the string
    if (exit_status) {
      break;
    }
  }
return 0;
}
