// This program prints an array of characters based on a specified number of
// column
#include <stdio.h>

#define MAXCOL 20
#define MAXINPUT 1000 // Define a maximum input size for storage

void print_char(char line[], int len);

int main() {
  char line[MAXINPUT + 1];
  int c, pos = 0;

  // Read the input and store it in the array
  while ((c = getchar()) != EOF && pos < MAXINPUT - 1 && c != '\n') {
    line[pos++] = c;
  }
  line[pos] = '\0'; // Null-terminate the string
  if (c == '\n') {
    print_char(line, MAXCOL);
  }
}
void print_char(char line[], int len) {
  // Print the entire array
  for (int i = 0; i < MAXCOL; i++) {
    putchar(line[i]);
  }
  putchar('\n');
}
