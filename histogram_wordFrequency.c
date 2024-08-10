#include <stdio.h>

#define MAX_CHARS 256

int main() {
    int char_freq[MAX_CHARS] = {0};
    int c;

    printf("Enter a text: ");

    while ((c = getchar()) != '\n') {
        if (c >= 0 && c < MAX_CHARS) {
            char_freq[(unsigned char)c]++;
        }
    }

    for (int i = 0; i < MAX_CHARS; i++) {
        if (char_freq[i] > 0) {
            printf("%c | ", (char)i);
            for (int j = 0; j < char_freq[i]; j++) {
                printf("*");
            }
            printf("\n");
        }
    }

    return 0;
}
