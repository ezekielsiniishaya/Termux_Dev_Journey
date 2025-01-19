#include <stdio.h>

#define MAX_LINES 5
#define MAX_LENGTH 100

int main() {
    char sentences[MAX_LINES][MAX_LENGTH];
    int i, j;

    printf("Enter %d lines of sentences (each line up to %d characters):\n", MAX_LINES, MAX_LENGTH - 1);

    for (i = 0; i < MAX_LINES; i++) {
        printf("Line %d: ", i + 1);
        j = 0;
        while (j < MAX_LENGTH - 1) {
            char ch = getchar();
            if (ch == '\n') {
                break;
            }
            sentences[i][j++] = ch;
        }
        sentences[i][j] = '\0'; // Null-terminate the string
    }

    printf("\nYou entered:\n");
    for (i = 0; i < MAX_LINES; i++) {
        printf("Line %d: ", i + 1);
        j = 0;
        while (sentences[i][j] != '\0') {
            putchar(sentences[i][j]);
            j++;
        }
        putchar('\n');
    }

    return 0;
}
