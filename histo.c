#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256

void print_histogram(const char *input) {
    int frequency[MAX_CHAR] = {0}; // Array to store the frequency of each character
    int i;

    // Count the frequency of each character in the input string
    for (i = 0; input[i] != '\0'; i++) {
        frequency[(unsigned char)input[i]]++;
    }

    // Print the histogram
    for (i = 0; i < MAX_CHAR; i++) {
        if (frequency[i] > 0) {
            printf("%c: ", i);
            for (int j = 0; j < frequency[i]; j++) {
                printf("#");
            }
            printf("\n");
        }
    }
}

int main() {
    char input[1000];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    // Remove the newline character at the end if it exists
    input[strcspn(input, "\n")] = '\0';

    print_histogram(input);

    return 0;
}

