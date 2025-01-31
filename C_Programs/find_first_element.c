#include <stdio.h>

#define MAX_ROWS 1000
#define MAX_COLUMNS 1000

<<<<<<< HEAD
int find_first_element(int array[][MAX_COLUMNS], int total_rows)
{
    for (int i = 0; i < total_rows; i++)
    {
        for (int column = 0; column < MAX_COLUMNS; column++)
        {
            if (array[i][column] != ' ' && array[i][column] != '\t' && array[i][column] != '\0')
            {
                return array[i][column]; // Return the first non-whitespace character
            }
        }
    }
    return -1; // No valid character found
}

int main()
{
    int array_2D[MAX_ROWS][MAX_COLUMNS] = {0}; // Initialize to prevent garbage values
    int row = 0, column = 0;
    int exit_status = 0;

    printf("Enter lines of code (press Ctrl+Z and Enter to stop on Windows):\n");

    while (row < MAX_ROWS)
    {
        char line[MAX_COLUMNS];
        if (fgets(line, MAX_COLUMNS, stdin) == NULL) // Read a full line
        {
            break; // Stop on EOF
        }

        // Store the input in array_2D
        for (column = 0; line[column] != '\0' && column < MAX_COLUMNS - 1; column++)
        {
            array_2D[row][column] = line[column];
        }
        array_2D[row][column] = '\0'; // Null-terminate
        row++;
    }

    int element = find_first_element(array_2D, row);

    if (element != -1)
    {
        printf("First non-whitespace character: %c\n", element);
    }
    else
    {
        printf("No valid character found.\n");
    }

    return 0;
=======
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
>>>>>>> c520e8f4ba3cb71307f8727e4fb50d9c27dd80f7
}
