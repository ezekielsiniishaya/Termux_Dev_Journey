/* This program removes comments from a given source code input. */

#include <stdio.h>

// Define constants for the maximum number of rows (lines) and columns

#define MAX_ROWS 2000
#define MAX_COLUMNS 2000

/* This function checks if a line starts with a ('/', '#', or '*').
It returns:
  - 1 if the line starts with a /,
  - 2 if it starts #,
  - 3 if it starts *,
  - 4 if it starts with any other non-whitespace character
  - -1 if the line is empty or contains only whitespace.
*/
int find_character(char array[][MAX_COLUMNS], int row, int column)
{
  while (array[row][column] != '\0')
  {
    if (array[row][column] != ' ' && array[row][column] != '\t')
    {
      if (array[row][column] == '/')
      {
        return 1;
      }
      else if (array[row][column] == '#')
      {
        return 2;
      }
      else if (array[row][column] == '*')
      {
        return 3;
      }
      else
      {
        return 4;
      }
    }
    column++;
  }
  return -1;
}

/* This function finds the index of the first semicolon (';') in a given row.
It returns the index of the semicolon or -1 if none is found. */

int find_semi_colon(char array[][MAX_COLUMNS], int row)
{
  int column = 0;
  while (array[row][column] != '\0')
  {
    if (array[row][column] == ';')
    {
      return column;
    }
    column++;
  }
  return -1;
}

/* This function finds the index of the start of a single-line comment ('//')
   in a given row. It returns the index of the comment start or -1 if no comment
   is found. */
int find_index_single(char array[][MAX_COLUMNS], int row, int column)
{
  while (array[row][column] != '\0')
  {
    if (array[row][column] == '/' && array[row][column + 1] == '/')
    {
      return column;
    }
    column++;
  }
  return -1;
}

/* This function finds the index of the start of a multi-line comment
   in a given row. It returns the index of the comment start or -1 if none is
   found. */
int find_index_multiple(char array[][MAX_COLUMNS], int row)
{
  int column = 0;
  while (array[row][column] != '\0')
  {
    if (array[row][column] == '/' && array[row][column + 1] == '*')
    {
      return column;
    }
    column++;
  }
  return -1;
}

/* This function finds the index of the end of a multi-line comment in a given
 * row. It returns the index of the comment end or -1 if none is found. */
int find_second_index(char array[][MAX_COLUMNS], int row, int column)
{

  while (array[row][column] != '\0')
  {
    if (array[row][column] == '*' && array[row][column + 1] == '/')
    {
      return column;
    }
    column++;
  }
  return -1;
}

// This function removes single-line comments ('//') from a given row of the array

void clear_single(char array[][MAX_COLUMNS], int row, int column)
{
  int single;
  while (array[row][column] != '\0')
  {
    single = find_index_single(array, row, column);
    if (single != -1)
    {
      array[row][single] = '\0'; // Terminate the string at the comment start
    }
    column++;
  }
}

// This function removes the first line of multi-line comments ('/* ... ') from a given row of the code array.

void clear_multiple(char array[][MAX_COLUMNS], int row, int index)
{
  array[row][index] = '\0'; // Terminate the string at the comment start
}

/* This function finds the first occurrence of a double quote (") in a row.
It returns the index of the quote or -1 if none is found. */
int find_quote(char array[][MAX_COLUMNS], int row)
{
  int column = 0;
  while (array[row][column] != '\0')
  {
    if (array[row][column] == '"')
    {
      return column;
    }
    column++;
  }
  return -1;
}

/* This function finds the second occurrence of a double quote (") after a given
start index. It returns the index of the closing quote or -1 if none is found. */

int find_second_quote(char array[][MAX_COLUMNS], int row, int start)
{
  int column = start + 1;
  while (array[row][column] != '\0')
  {
    if (array[row][column] == '"')
    {
      return column;
    }
    column++;
  }
  return -1;
}

/* This function processes the 2D array of code and removes both
   single-line and multi-line comments. It iterates through each row,
   identifies comments, and removes them by modifying the array. It considers comments in strings and character constants*/
void clear_array(char array[][MAX_COLUMNS], int row)
{
  int i = 0;
  int character, single, multiple;
  int column = 0;
  int second = -1, found = -1;
  int start, stop;

  while (i < row)
  {
    // Checks the first non-blank character of each line
    character = find_character(array, i, column);

    // Line of code with strings
    if (character == 4)
    {
      start = find_quote(array, i);
      if (start != -1)
      {
        stop = find_second_quote(array, i, start);
        if (stop != -1)
        {
          single = find_index_single(array, i, stop);
          if (single != -1)
          {
            array[i][single] = '\0';
          }
        }
      }
      // Line of code without strings
      else
      {
        int colon = 1; // find_semi_colon(array, i);
        if (colon != -1)
        {
          single = find_index_single(array, i, colon);
          multiple = find_index_multiple(array, i);
          if (single != -1)
          {
            array[i][single] = '\0';
          }
          if (multiple != -1)
          {
            found = 1;
            clear_multiple(array, i, multiple);
          }
        }
      }
    }
    // Line starts with a #
    if (character == 2)
    {
      // Check for single line or multiple line comment
      single = find_index_single(array, i, 0);
      multiple = find_index_multiple(array, i);
      if (single != -1)
      {
        clear_single(array, i, single);
      }
      else if (multiple != -1)
      {
        clear_multiple(array, i, multiple);
      }
    }
    // Line starts with a comment
    if (character == 1)
    {
      int check = find_character(array, i, column + 1);

      // Check for single line or multiple line comment
      if (check == 1)
      {
        clear_single(array, i, 0);
      }
      if (check == 3)
      {
        multiple = find_index_multiple(array, i);
        if (multiple != -1)
        {
          int k = multiple + 2;
          for (int j = i; j < row; j++)
          {
            second = find_second_index(array, j, k);
            if (second != -1)
            {
              array[j][0] = '\0';
              break;
            }
            array[j][0] = '\0';
            i++;
            k = 0;
          }
        }
      }
    }

    i++;
  }
}

/* This function checks if a row contains only whitespace characters.
It returns the index of the first non-whitespace character or -1 if the row is empty. */

int find_blank_lines(char array[][MAX_COLUMNS], int row)
{
  int column = 0;
  while (array[row][column] != '\0')
  {
    if (array[row][column] != ' ' && array[row][column] != '\t')
    {
      return column;
    }
    column++;
  }
  return -1;
}

/* This function prints the 2D array of code, displaying the code
   without comments. */
void print_array(char array[][MAX_COLUMNS], int len)
{
  printf("\nCode without comments:\n");
  for (int row = 0; row < len; row++)
  {
    int column = 0;
    int start = -1;
    int check = find_blank_lines(array, row);
    int check2;
    if (check != -1)
    {
      start = 1;
    }
    if ((row + 1) < len)
    {
      check2 = find_blank_lines(array, row + 1);
    }
    if (check2 != -1)
    {
      start = 1;
    }
    if (start != -1)
    {
      while (array[row][column] != '\0')
      {
        putchar(array[row][column]);
        column++;
      }
      putchar('\n');
      start = -1;
    }
  }
}

/* The main function reads lines of code from user input, processes
   them to remove comments, and prints the cleaned code. */
int main()
{
  char array_2D[MAX_ROWS][MAX_COLUMNS]; // Array to store the input code
  int row, column;
  int exit_status = 0;

  printf(
      "Enter up to %d lines of code (each up to %d characters). Press "
      "'Ctrl+D' to stop:\n",
      MAX_ROWS, MAX_COLUMNS - 1);

  for (row = 0; row < MAX_ROWS; row++)
  {
    column = 0;
    while (column < MAX_COLUMNS - 1)
    {
      int character = getchar();
      if (character == EOF)
      {
        exit_status = 1;
        break;
      }
      if (character == '\n')
      {
        break;
      }
      array_2D[row][column++] = (char)character;
    }
    array_2D[row][column] = '\0';
    if (exit_status)
    {
      break;
    }
  }

  clear_array(array_2D, row);
  print_array(array_2D, row);

  return 0;
}
