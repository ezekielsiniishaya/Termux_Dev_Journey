// This is a program that folds long lines of input based on the specified maximum number of column

#include <stdio.h>

#define MAXCOL 20                           /* folded line length */
#define TABVAL 8                            /* standard tab length */
#define CURTAB(c) (TABVAL - ((c) % TABVAL)) /* current tab size */
#define NO_BLANK -1                         /* signifies no blank found */

/* Function to find the last whitespace character in an array */
int find_last_blank(const char line[], int length)
{
  for (int i = length - 1; i >= 0; i--)
  {
    if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
    {
      return i; /* Return the position of the last blank or tab */
    }
  }
  return NO_BLANK;
}

/* Function to print the current line up to a given length */
void print_line(const char line[], int length)
{
  for (int i = 0; i < length; i++)
  {
    putchar(line[i]);
  }
}

/* Function to fold a line at the last blank before the max column */
int fold_line(char line[], int pos, int col)
{
  int last_blank = find_last_blank(line, pos);

  if (last_blank != NO_BLANK)
  {
    /* Fold line at the last blank */
    print_line(line, last_blank);
    putchar('\n'); /* Start a new line */

    /* Move remaining characters to the buffer */
    int i, j;
    for (i = 0, j = last_blank + 1; j < pos; ++i, ++j)
    {
      line[i] = line[j];
    }
    return i; /* Return updated position in buffer */
  }
  else
  {
    /* If no blank found, print the line as it is */
    print_line(line, pos);
    putchar('\n'); /* Start a new line */
    return 0;      /* Reset buffer */
  }
}

/* Function to process each character and fold lines when necessary */
void process_input(void)
{
  int c;                 /* Current character */
  int pos = 0;           /* Current position in array */
  int col = 0;           /* Current column in the output */
  char line[MAXCOL + 1]; /* Buffer to hold characters before folding */

  while ((c = getchar()) != EOF)
  {
    /* Add character to buffer and track column */
    line[pos++] = c;
    col += (c == '\t') ? CURTAB(col) : 1;

    /* Check if line needs folding */
    if (col >= MAXCOL || c == '\n')
    {
      pos = fold_line(line, pos, col); /* Fold the line */
      col = 0;
      for (int i = 0; i < pos; ++i)
      {
        col += (line[i] == '\t') ? CURTAB(col) : 1; /* Recalculate column */
      }
    }
  }

  /* Process leftover characters in the buffer after EOF */
  if (pos > 0)
  {
    print_line(line, pos); /* Print remaining characters */
    putchar('\n');         /* Add newline for consistency */
  }
}

int main(void)
{
  process_input(); /* Start processing the input */
  return 0;
}
