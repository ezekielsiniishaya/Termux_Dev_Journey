// This is a program that folds long line of characters based on the specified maximum colum(MAXCOL)

#include <stdio.h>

#define MAXCOL 20                           // Max characters to be printed before foldiing
#define TABVAL 8                            // Current tab value
#define CURTAB(c) (TABVAL - ((c) % TABVAL)) // Calculates the exact number of characters a Tab occupies
#define NO_BLANK -1                         // Signifies whether there is a blank in a line or not

int find_last_blank(char line[], int length)
{
  for (int i = length - 1; i >= 0; i--)
  {
    if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
    {
      return i;
    }
  }
  return NO_BLANK;
}

void print_line(char line[], int length)
{
  for (int i = 0; i < length; i++)
  {
    putchar(line[i]);
  }
}

int fold_line(char line[], int length)
{
  int last_blank = find_last_blank(line, length);

  if (last_blank != NO_BLANK)
  {
    print_line(line, last_blank);
    putchar('\n');
    // Move the remaing characters to the front of the array and update the lenght of the array to only contain the unprinted characters
    int i, j;
    for (i = 0, j = last_blank + 1; j < length; i++, j++)
    {
      line[i] = line[j];
    }
    return i;
  }
  else
  {
    print_line(line, length);
    putchar('\n');
    return 0;
  }
}

void read_line()
{
  int c;       // Stores the current character being read
  int pos = 0; // Tracks the current character
  int col = 0; // Tracks the current column

  char line[MAXCOL + 1]; // The array to store the characters, space for the null-terminator was considered

  while ((c = getchar()) != EOF)
  {
    line[pos++] = c;
    col += (c == '\t') ? CURTAB(col) : 1;

    if (col >= MAXCOL || c == '\n')
    {
      pos = fold_line(line, pos);
      col = 0;
      for (int i = 0; i < pos; i++)
      {
        col += (line[i] == '\t') ? CURTAB(col) : 1;
      }
    }
  }
  if (pos > 0)
  {
    print_line(line, pos);
    putchar('\n');
  }
}

int main()
{
  read_line();
  return 0;
}
