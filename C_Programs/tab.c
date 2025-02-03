#include <stdio.h>

#define TAB_STOP 8

int main() {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            for (int i = 0; i < TAB_STOP; i++) {
                putchar(' ');
            }
           
        } else if (c == '\n') {
            putchar(c);
        
        } else {
            putchar(c);
           
        }
        // Debugging line: Uncomment to see positions
        // printf("Current pos: %d\n", pos);
    }

    return 0;
}


