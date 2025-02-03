#include <stdio.h>

#define MAX_ROWS 5
#define MAX_COLUMNS 10

void clear_array(char array[][MAX_COLUMNS]) {
  
  printf("in clear function");
  for (int i = 0; i <= MAX_ROWS; i++) {
    int column = 0;
    printf("in clear function2");
    while(array[i][column] != '\0'){
    array[i][column] = '\0';
    column++;
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
  }
}
int main() {
  char array_2D[MAX_ROWS][MAX_COLUMNS];
  int row, column;

  printf(
      "Enter %d lines of sentences (each line up to %d characters). Word "
      "must not start with letter d:\n",
      MAX_ROWS, MAX_COLUMNS - 1);

  for (row = 0; row < MAX_ROWS; row++) {
    printf("Line %d: ", row + 1);
    column = 0;
    while (column < MAX_COLUMNS - 1) {
      char character = getchar();
      if (character == '\n') {
        array_2D[row][column++] = character;
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
