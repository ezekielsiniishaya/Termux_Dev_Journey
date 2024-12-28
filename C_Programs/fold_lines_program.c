// Program that fold long input lines to shorter ones based on MAXCOL
#include <stdio.h>

#define MAXCOL 20     // The maximum column before folding
#define MAXCHAR 1000  // Maximum number of characters per line
// Function prototypes
void print_line(char line[], int length);
int find_last_blank(char line[], int max);
void fold_line(char line[], int len);
void clear_line(char line[], int len);
int main() {
  int c,
      pos = 0;             // 'c' holds the character input, 'pos' tracks position in the line
  char line[MAXCHAR + 1];  // Array to store the current line, with room for the
                           // null-terminator

  // Read input character by character until EOF is reached
  while ((c = getchar()) != EOF) {
    line[pos] = c;  // Store the character in the line array
    if (c == '\n') {
      print_line(line, pos);
      pos = 0;
      putchar('\n');
      // clear_line(line, pos);
    } else if (pos >= MAXCOL) {
      fold_line(line, pos);
      pos = 0;
    } else {
      pos++;
    }
  }
}
// Function to print the current line up to the specified length
void print_line(char line[], int length) {
  for (int i = 0; i <= length; i++) {
    putchar(line[i]);  // Output each character in the line
  }
}
void clear_line(char line[], int len) {
  for (int i = 0; i <= len; i++) {
    line[i] = '\0';  // Output each character in the line
  }
}

// Function to find the last blank space or tab before the max position in the
// line
int find_last_blank(char line[], int max) {
  for (int i = max; i >= 0; i--) {
    if (line[i] == ' ' || line[i] == '\t') {
      return i;  // Return the index of the last space or tab
    }
  }
  return -1;  // Return -1 if no blank space or tab is found
}

// Function to fold the line at the last blank space or tab before the max
// position

void fold_line(char line[], int max) {
  int last_blank = find_last_blank(line, max);
  if (last_blank > 0) {
    print_line(line, last_blank);
    putchar('\n');
    print_line(&line[last_blank + 1], max - last_blank);
  } else {
    print_line(line, MAXCOL - 1);
    putchar('-');
    putchar('\n');
    print_line(&line[MAXCOL], max - MAXCOL);
  }
}
