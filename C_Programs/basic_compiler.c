/* This is a basic C compiler program to check a C program for rudimentary
 * syntax errors like unmatched parentheses, brackets and brace */

#include <stdio.h>

#define MAX_ROWS 2000
#define MAX_COLUMNS 2000

// Function prototypes
int read_code(char array[MAX_ROWS][MAX_COLUMNS]);
void compile_code(char array[MAX_ROWS][MAX_COLUMNS], int rows);
int find_character(char array[][MAX_COLUMNS], int row);
int find_semi_colon(char array[][MAX_COLUMNS], int row);
int find_index_multiple(char array[][MAX_COLUMNS], int row);
int read_char(char array[][MAX_COLUMNS], int row);
int main() {
  // Array to store the code
  char code[MAX_ROWS][MAX_COLUMNS];
  int rows_used = read_code(code);
  printf("Rows: %d\n", rows_used);
  compile_code(code, rows_used);
  return 0;
}
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
    return -1; // Multi-line comment
  } else if (array[row][column] == '#') {
    return -2; // Preprocessor directive
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
// Function to process the code and identify comment lines empty lines, or
// instruction lines, or # lines
void compile_code(char array[][MAX_COLUMNS], int rows) {
  printf("\nOUTPUT:\n");
  for (int i = 0; i < rows; i++) {
    int result = find_character(array, i);

    switch (result) {
    case 0:
      printf("Line: %d is a single comment line\n", i + 1);
      break;
    case -1:
      printf("Line: %d is a multi line comment line\n", i + 1);
      int nest = read_char(array, result);
      if (nest == 1) {
        printf("Multiline comment don't nest in C.");
      }
      break;
    case -2:
      printf("Line: %d is Preprocessor directive line\n", i + 1);
      break;
    case -3:
      printf("Line: %d is an instruction line\n", i + 1);
      break;
    case -4:
      printf("Line: %d is an empty line\n", i + 1);
      break;
    default:
      printf("Line: %d is unrecognized\n", i + 1);
    }
  }
}
// This funcrion finds the end of an instruction line
/* This function finds of semicolon (';') in a given row. It returns the index
 * of the semicolon or -1 if none is found. */

int find_semi_colon(char array[][MAX_COLUMNS], int row) {
  int column = 0;
  while (array[row][column] != '\0') {
    if (array[row][column] == ';') {
      return column;
    }
    column++;
  }
  return -1;
}
/* This function finds the index of the end of a multi-line comm
ent in a given
 * row. It returns the index of the comment closing tag or -1 if none is found.
*/
int read_char(char array[][MAX_COLUMNS], int row) {
  int column = 0;
  while (array[row][column] != '\0') {
    if (array[row][column] == '/' && array[row][column + 1] == '*') {
      return 1;
    }
    column++;
  }
  return -1;
}
