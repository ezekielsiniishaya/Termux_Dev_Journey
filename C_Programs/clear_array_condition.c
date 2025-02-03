/* This program, somehow, successfully deletes a specified element from an array
 */
#include <stdio.h>

#define MAX_ROWS 5
#define MAX_COLUMNS 10
/* This function seems redundant but it returns the index of the element to be
 * deleted */
int find_index(char array[][MAX_COLUMNS], int row, int column) {
  if (array[row][column] == 'd') {
    return column;
  }

  return -1;
}
/* Here is where the quirky behaviour happens. The char element is replaced with
 * 1, which is not jn character format so it just gets ignored */
void clear_array(char array[][MAX_COLUMNS]) {
  int i = 0;
  int column = 0;
  for (i = 0; i < MAX_ROWS; i++) {
    for (int j = 0; j < MAX_COLUMNS; j++) {
      column = find_index(array, i, j);
      if (column != -1) {
        array[i][column] = 1;
      }
    }
  }
}
void print_array(char array[][MAX_COLUMNS]) {
  printf("\nYou entered:\n");
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
      "Enter %d lines of sentences (each line up to %d characters). Word "
      "must not contain letter d:\n",
      MAX_ROWS, MAX_COLUMNS - 1);

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

  clear_array(array_2D);
  print_array(array_2D);
  return 0;
}
