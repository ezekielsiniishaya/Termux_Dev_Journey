//program to replace spaces with tabs and then spaces while maintaining the given space
#include <stdio.h>

#define TAB_STOP 8  // You can change this to any value

int main() {
    int c;
    int space_count = 0;
    int pos = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            space_count++;
            pos++;

            // Check if we hit a tab stop
            if (pos % TAB_STOP == 0) {
                putchar('\t');  // Replace spaces with a tab
                space_count = 0;
            }
        } else {
            // Output any accumulated spaces
            while (space_count > 0) {
                putchar(' ');
                space_count--;
            }

            if (c == '\n') {
                putchar(c);
                pos = 0;  // Reset position on new line
            } else {
                putchar(c);
                pos++;  // Update position
            }
        }
    }

    return 0;
}

