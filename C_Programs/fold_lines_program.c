#include <stdio.h>

#define MAXCOL 20                           /* folded line length */
#define TABVAL 8                            /* standard tab length */
#define CURTAB(c) (TABVAL - ((c) % TABVAL)) /* current tab size */
#define NO_BLANK -1                         /* signifies no blank found */

/* Function to find the last whitespace character in an array */
int lastblank(const char arr[], int len) {
  int i, lbc = NO_BLANK;

  for (i = 0; i < len; ++i) {
    if (arr[i] == ' ' || arr[i] == '\t') {
      lbc = i; /* Update the position of the last blank or tab */
    }
  }
  return lbc;
}

/* Function to print the current line up to a given length */
void print_line(char line[], int length) {
  for (int i = 0; i < length; i++) {
    putchar(line[i]);
  }
}

/* Function to fold a line at the last blank before the max column */
void fold_line(char line[], int* pos, int* col) {
  int lbc = lastblank(line, *pos);

  if (lbc != NO_BLANK) {
    /* Fold line at the last blank */
    print_line(line, lbc);
    putchar('\n'); /* Start a new line */

    /* Move remaining characters to the buffer */
    int i, j;
    for (i = 0, j = lbc + 1, *col = 0; j < *pos; ++i, ++j) {
      line[i] = line[j];
      *col += (line[i] == '\t') ? CURTAB(*col) : 1; /* Update column */
    }
    *pos = i; /* Update position in buffer */
  } else {
    /* If no blank found, print the line as it is */
    print_line(line, *pos);
    putchar('\n'); /* Start a new line */
    *col = *pos = 0; /* Reset buffer and column count */
  }
}

/* Function to process each character and fold lines when necessary */
void process_input(void) {
  int c;                 /* Current character */
  int pos = 0;           /* Current position in array */
  int col = 0;           /* Current column in the output */
  char line[MAXCOL + 1]; /* Buffer to hold characters before folding */

  while ((c = getchar()) != EOF) {
    /* Add character to buffer and track column */
    line[pos++] = c;
    col += (c == '\t') ? CURTAB(col) : 1;

    /* Check if line needs folding */
    if (col >= MAXCOL || c == '\n') {
      line[pos] = '\0'; /* Null-terminate the buffer */
      fold_line(line, &pos, &col); /* Fold the line */
    }
  }

  /* Process leftover characters in the buffer after EOF */
  if (pos > 0) {
    line[pos] = '\0';    /* Null-terminate the buffer */
    print_line(line, pos); /* Print remaining characters */
    putchar('\n');       /* Add newline for consistency */
  }
}

int main(void) {
  process_input(); /* Start processing the input */
  return 0;
}
