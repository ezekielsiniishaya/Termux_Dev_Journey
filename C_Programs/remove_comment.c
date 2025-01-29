/* This program, somehow, successfully deletes a specified element from an array
 */
#include <stdio.h>

#define MAX_ROWS 3
#define MAX_COLUMNS 120
/* This function seems redundant but it returns the index of the element \
      to be deleted */
int find_index(char array[][MAX_COLUMNS], int row) {
  for (int i = 0; i < MAX_COLUMNS; i++) {
    if (array[row][i] == '/' && (array[row][i + 1] == '/' || array[row][i + 1] == '*')) {
      return i;
    }
  }

  return -1;
} /* Here is where the quirky behaviour happens. The char element is replaced
     with 1, which is not jn character format so it just gets ignored */
void clear_array(char array[][MAX_COLUMNS]) {
  int i = 0;
  int column = 0;
  for (i = 0; i < MAX_ROWS; i++) {
    column = find_index(array, i);
    if (column != -1) {
      array[i][column] = '\0';
    }
    column++;
  }
}
void print_array(char array[][MAX_COLUMNS]) {
  printf("\nCodes without comments:\n");
  for (int row = 0; row < MAX_ROWS; row++) {
    int column = 0;
    while (array[row][column] != '\0') {
      putchar(array[row][column]);
      column++;
    }
    putchar('\n');
  }
}
int main() {
  char array_2D[MAX_ROWS][MAX_COLUMNS];
  int row, column;

  printf(
      "Enter %d lines of code (each line up to %d characters). All "
      "comements will be cleared:\n",
      MAX_ROWS, MAX_COLUMNS - 1);
  for (row = 0; row < MAX_ROWS; row++) {
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
  clear_array(array_2D);
  print_array(array_2D);
  return 0;
}
