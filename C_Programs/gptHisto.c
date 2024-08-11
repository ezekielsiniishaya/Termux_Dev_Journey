#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20
#define MAX_WORDS 100

void print_vertical_histogram(int word_lengths[], int max_length, int max_count) {
    for (int i = max_count; i > 0; i--) {
        for (int j = 1; j <= max_length; j++) {
            if (word_lengths[j] >= i) {
                printf(" * ");
            } else {
                printf("   ");
            }
        }
        printf("\n");
    }

    for (int j = 1; j <= max_length; j++) {
        printf(" %d ", j);
    }
    printf("\n");
}

int main() {
    char input[1000];
    printf("Enter text: ");
    fgets(input, sizeof(input), stdin);

    int word_lengths[MAX_WORD_LENGTH + 1] = {0};
    int max_length = 0;
    int max_count = 0;

    char *word = strtok(input, " \n\t");
    while (word != NULL) {
        int length = strlen(word);
        if (length > MAX_WORD_LENGTH) {
            length = MAX_WORD_LENGTH;
        }
        word_lengths[length]++;
        if (length > max_length) {
            max_length = length;
        }
        if (word_lengths[length] > max_count) {
            max_count = word_lengths[length];
        }
        word = strtok(NULL, " \n\t");
    }

    print_vertical_histogram(word_lengths, max_length, max_count);

    return 0;
}

