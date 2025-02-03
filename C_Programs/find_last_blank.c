
// This program finds the last blank character before or at a specifed column is
// reached

#include <stdio.h>

#define MAXCOL 10    // Definea maximum column
#define MAXINPUT 100 // Define a maximum input size for storage

// Function prototype to find last blank
int find_last_blank(char line[], int max);

int main() {
  char line[MAXINPUT];
  int c, pos = 0;

  // Read the input and store it in the array
  while ((c = getchar()) != EOF && pos < MAXINPUT - 1 && c != '\n') {
    line[pos++] = c;
  }
  line[pos] = '\0'; // Null-terminate the string
  if (c == '\n') {
    // Find and print the last blank before maxcol
    int blank = find_last_blank(line, MAXCOL);
    printf("Last blank before maxcol: %d\n", blank);

    return 0;
  }
}

int find_last_blank(char line[], int max) {
  // Search for the last blank before or at maxcol
  for (int i = max - 1; i >= 0; i--) {
    if (line[i] == ' ' || line[i] == '\t') {
      return i;
    }
  }
  return -1; // No blank found
}
