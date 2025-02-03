#include <stdio.h>

#define MAX_WORDS 10

int main() {
    int num_words[MAX_WORDS] = {0};
    int num_input = 0;

    printf("Enter text: ");

    int c = getchar();
    while (c != EOF) { // read until newline
        if (c == ' ' || c == '\n') { // if space, increment word length count
            if (num_input <=  MAX_WORDS) {
		num_words[num_input]++;
            }
            num_input = 0;
        } else {
            num_input++; // increment word length
        }

        c = getchar(); // read next character
    }

    // Print histogram
    for (int i = 1; i <= MAX_WORDS; i++) {
        printf("%2d | ", i);
        for (int j = 0; j < num_words[i]; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
