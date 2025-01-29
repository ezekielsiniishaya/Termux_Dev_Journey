/* This program clears comments from a program */
#include <stdio.h>

// Define constants for the maximum number of rows and columns in the code array
#define MAX_ROWS 20
#define MAX_COLUMNS 120

/* This function finds the index of the start of a single-line comment (//) in a
   given row. It returns the index of the comment start, or -1 if no comment is
   found. */
int find_index_single(char array[][MAX_COLUMNS], int row) {
  // Iterate through each column of the specified row
  for (int i = 0; i < MAX_COLUMNS; i++) {
    // Check if the current character and the next one form a single-line
    // comment (//)
    if (array[row][i] == '/' && (array[row][i + 1]) == '/') {
      return i;  // Return the index of the comment start
    }
  }
  return -1;  // Return -1 if no comment is found
}

/* This function finds the index of the start of a multi-line comment in a
   given row. It returns the index of the comment start, or -1 if no comment is
   found. */
int find_index_multiple(char array[][MAX_COLUMNS], int row) {
  // Iterate through each column of the specified row
  for (int i = 0; i < MAX_COLUMNS; i++) {
    // Check if the current character and the next one form a multi-line comment
    // (/*)
    if (array[row][i] == '/' && (array[row][i + 1]) == '*') {
      return i;  // Return the index of the comment start
    }
  }
  return -1;  // Return -1 if no comment is found
}

/* This function finds the index of the end of a multi-line comment (* /) in a
   given row. It returns the index of the comment end, or -1 if no end is found.
 */
int find_second_index(char array[][MAX_COLUMNS], int row) {
  // Iterate through each column of the specified row
  for (int i = 0; i < MAX_COLUMNS; i++) {
    // Check if the current character and the next one form the end of a
    // multi-line comment (* /)
    if (array[row][i] == '*' && (array[row][i + 1]) == '/') {
      return i;  // Return the index of the comment end
    }
  }
  return -1;  // Return -1 if no end of comment is found
}

/* This function processes the 2D array of code and removes both single-line and
   multi-line comments. It iterates through each row, identifies comments, and
   removes them by modifying the array. */
void clear_array(char array[][MAX_COLUMNS]) {
  int i = 0;
  int single, multiple = 0;  // Variables to store indices of comments
  for (i = 0; i < MAX_ROWS; i++) {
    // Find the starting index of single-line and multi-line comments
    single = find_index_single(array, i);
    multiple = find_index_multiple(array, i);

    // If a single-line comment is found, remove it by null-terminating the
    // string from that point
    if (single != -1) {
      array[i][single] = '\0';
    }

    // If a multi-line comment is found, remove it and continue looking for the
    // end of the comment
    if (multiple != -1) {
      array[i][multiple] = '\0';  // Remove the start of the multi-line comment
      int j;
      // Search for the end of the multi-line comment across subsequent rows
      for (j = i; j < MAX_ROWS; j++) {
        int second = find_second_index(array, j);
        if (second != -1) {
          break;  // Stop when the comment ends
        }
        array[j + 1][0] = '\0';  // Clear rows between the start and end of the comment
      }
      single++;    // Move past the single-line comment start (if any)
      multiple++;  // Move past the multi-line comment start (if any)
    }
  }
}

/* This function prints the 2D array of code, displaying the code without
 * comments. */
void print_array(char array[][MAX_COLUMNS]) {
  printf("\nCodes without comments:\n");
  // Iterate through each row in the array
  for (int row = 0; row < MAX_ROWS; row++) {
    int column = 0;
    // Print characters until a null-terminator is encountered
    while (array[row][column] != '\0') {
      putchar(array[row][column]);
      column++;
    }
    putchar('\n');  // Print a new line after each row
  }
}

/* The main function where the program starts.
   It reads lines of code from the user, processes them to remove comments,
   and then prints the code without comments. */
int main() {
  char array_2D[MAX_ROWS][MAX_COLUMNS];  // 2D array to store code input
  int row, column;

  // Prompt the user to enter lines of code
  printf(
      "Enter %d lines of code (each line up to %d characters). All "
      "comments will be cleared:\n",
      MAX_ROWS, MAX_COLUMNS - 1);

  // Read input lines from the user
  for (row = 0; row < MAX_ROWS; row++) {
    column = 0;
    // Read characters for each row until the end of the line
    while (column < MAX_COLUMNS - 1) {
      char character = getchar();
      if (character == '\n') {
        break;  // Stop when a new line is encountered
      }
      array_2D[row][column++] = character;  // Store the character in the array
    }
    array_2D[row][column] = '\0';  // Null-terminate the string to mark the end of the row
  }

  // Call the function to remove comments
  clear_array(array_2D);

  // Print the code without comments
  print_array(array_2D);

  return 0;  // Exit the program
}
