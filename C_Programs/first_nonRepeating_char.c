#include <stdio.h>

#define MAXLINE 5 /* maximum input line length */

int get(char line[], int maxline);
void copy(char to[], char from[]);
void print(char arr[]);
/* print the longest input line */
int main() {
  int len;               /* current line length */
  int max;               /* maximum length seen so far */
  char line[MAXLINE];    /* current input line */
  char longest[MAXLINE]; /* longest line saved here */
  int tempLen = 0;       /* for storing partial lengths */

  max = 0;
  while ((len = get(line, MAXLINE)) > 0) {
    tempLen += len;
    if (line[len - 1] != '\n' && len == MAXLINE - 1) {
      continue; /* Line is longer than MAXLINE, continue reading */
    }

    if (tempLen > max) {
      max = tempLen;
      copy(longest, line); /* Save the current (partial) line */
    }

    tempLen = 0; /* Reset the partial length counter */
  }

  if (max > 0) { /* There was a line */
    printf("Longest line length: %d\n", max);
    printf("Longest Input (as much as possible): %s\n", longest);
  }

  return 0;
}

/* getline: read a line into s, return length */
int get(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    s[i] = c;
  }

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';
  return i;
}

/* copy: copy 'from' into 'to'; assume 'to' is big enough */
void copy(char to[], char from[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}
