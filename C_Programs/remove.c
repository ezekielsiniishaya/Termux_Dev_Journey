#include <stdio.h>

#define MAX_ROWS 5
#define MAX_COLUMNS 10

int main() {
  char array_2D[MAX_ROWS][MAX_COLUMNS];
  int i,
  j;

  printf("Enter %d lines of sentences (each line up to %d characters):\n", MAX_ROWS, MAX_COLUMNS - 1);

  for (i = 0; i < MAX_ROWS; i++) {
    printf("Line %d: ", i + 1);
    j = 0;
    while (j < MAX_COLUMNS - 1) {
      char ch = getchar();
      if (ch == '\n') {
        array_2D[i][j++] = ch;
        break;
      }
      array_2D[i][j++] = ch;
    }
    array_2D[i][j] = '\0'; // Null-terminate the string
  }

  printf("\nYou entered:\n");
  for (i = 0; i < MAX_ROWS; i++) {
    j = 0;
    while (array_2D[i][j] != '\0') {
      putchar(array_2D[i][j]);
      j++;
    }
    //putchar('\n');
  }

  return 0;
}
