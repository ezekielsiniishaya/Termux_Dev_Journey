#include <stdio.h>

int main() {
    int ch;

    printf("Enter text (Ctrl+D to end input on Unix-like systems or Ctrl+Z on Windows):\n");

    while ((ch = getchar()) != EOF) {
        putchar(ch);
    }

    printf("\nThe value of EOF is: %d\n", EOF);

    return 0;
}

