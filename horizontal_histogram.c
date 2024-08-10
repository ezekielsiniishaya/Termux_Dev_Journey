#include <stdio.h>

#define MAX_WORD_LENGTH 20
#define MAX_HISTOGRAM_HEIGHT 10

int main() {
    int word_length[MAX_WORD_LENGTH] = {0};
    int max_length = 0;
    int c, length = 0;

    // Count word lengths
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (length > 0) {
                if (length < MAX_WORD_LENGTH) {
                    word_length[length]++;
                } else {
                    word_length[MAX_WORD_LENGTH - 1]++;
                }
                length = 0;
            }
        } else {
            length++;
        }
    }

    // Find maximum word length
    for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        if (word_length[i] > max_length) {
            max_length = word_length[i];
        }
    }

    // Print histogram
    for (int i = 0; i < MAX_WORD_LENGTH; i++) {
        printf("%2d:", i);
        int bar_length = (word_length[i] * MAX_HISTOGRAM_HEIGHT) / max_length;
        for (int j = 0; j < bar_length; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
