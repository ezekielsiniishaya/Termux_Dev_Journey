#include <stdio.h>

#define TAB_STOP 12

int main() {
    int c, pos = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            int spaces = TAB_STOP - (pos % TAB_STOP);
            for (int i = 0; i < spaces; i++) {
                putchar(' ');  // Corrected syntax: putchar(' ')
            }
            pos += spaces;  // Update position counter

        } else if (c == '\n') {
            putchar(c);  // Corrected syntax: putchar(c)
            pos = 0;  // Reset position counter on new line
        } else {
            putchar(c);  // Corrected syntax: putchar(c)
            pos++;  // Update position counter
        }
    }

    return 0;
}

