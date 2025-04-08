/* Program to find the length of longest non-repeating sub-string from an array */

#include <stdio.h>
#include <string.h>

// Returns the length of longes
int longest_sub_str(char str[], int str_length) {
  int longest_sub = 0; // stores longest sub-string
  int base = 0;        // Current sub-string start
  int start = 1;       // Current sub-string count start
  int count = 1;       // Current length of sub-string
  int add_count = 0;   // checks for non-repeating characters before counting longest_sub
  int current;         // Stores the index of the current char under consideration
  printf("length = %d\n", str_length);
  while (base < str_length && start < str_length) {
    printf("Begin count = %d, start = %d\n", count, start);
    for (current = start - 1; current >= base; current--) {
      printf("base = %d\n", base);
      if (str[start] != str[current]) {
        add_count = 1;
      } else {
        add_count = 0;
        start = 0;
        break;
      }
    }
    if (add_count == 1) {
      count++;
    } else {
      start = base + 1;
      base++;
      printf("Substring length = %d\n", count);
      count = 1;
    }
    printf("final Substring length = %d\n", count);
    start++;
    printf("End count = %d, start = %d, add = %d\n", count, start, add_count);
    if (count > longest_sub) {
      longest_sub = count;
    }
  }
  return longest_sub;
}
int main() {
  char str[] = {"aaaaaaaa"};    // String array
  int str_length = strlen(str); // Calculates thelength of arr
  int output = longest_sub_str(str, str_length);
  printf("%s\n", str);
  printf("Length of longest sub-string is %d\n", output);
  return 0;
}
