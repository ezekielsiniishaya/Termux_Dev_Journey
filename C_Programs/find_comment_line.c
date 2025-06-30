#include <stdio.h>

#define MAX_ROWS 20
#define MAX_COLUMNS 100

// Function to receive code and save it in the array
int read_code(char array[MAX_ROWS][MAX_COLUMNS]) {
  int row = 0;
  printf("Paste your code (Ctrl+D to submit):\n");

  while (row < MAX_ROWS) {
    int col = 0;
    int ch;

    // Adding to array line by line
    while (col < MAX_COLUMNS - 1 && (ch = getchar()) != EOF && ch != '\n') {
      array[row][col++] = (char)ch;
    }

    array[row][col] = '\0'; // Null-terminate the line

    if (ch == EOF) {
      if (col > 0 || row == 0)
        row++;
      break;
    }

    // Start adding on a new line when newline is reached
    row++;
  }
  return row;
}

// This function checks what kind of line it is
int find_character(char array[][MAX_COLUMNS], int row) {
  int column = 0;

  // Skip leading whitespace
  while (array[row][column] == ' ' || array[row][column] == '\t') {
    column++;
  }

  // Check if the remaining line starts with a comment
  if (array[row][column] == '/' && array[row][column + 1] == '/') {
    return 0; // Single-line comment
  } else if (array[row][column] == '/' && array[row][column + 1] == '*') {
    return 0; // Multi-line comment
  } else if (array[row][column] == '#') {
    return -1; // Preprocessor directive
  }

  // Now check if the whole line has only whitespace or comment
  while (array[row][column] != '\0') {
    if (array[row][column] != ' ' && array[row][column] != '\t') {
      return -3; // Line has actual code (or code + comment)
    }
    column++;
  }

  return -4; // Empty or whitespace-only line
}
// Function to process the code and identify comment lines
void compile_code(char array[][MAX_COLUMNS], int rows) {
  printf("\nOUTPUT:\n");

  for (int i = 0; i < rows; i++) {
    int result = find_character(array, i);

    if (result == 0) {
      printf("Line: %d is a comment line\n", i + 1);
    }
  }
}

int main() {
  char code[MAX_ROWS][MAX_COLUMNS];
  int total_lines = read_code(code);
  compile_code(code, total_lines);

  return 0;
}
