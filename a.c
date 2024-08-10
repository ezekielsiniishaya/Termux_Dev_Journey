#include <stdio.h>

// Function to convert an integer to a binary string
void intToBinary(int n, char *binaryStr) {
    for (int i = 7; i >= 0; i--) {
        binaryStr[7 - i] = (n & (1 << i)) ? '1' : '0';
    }
    binaryStr[8] = '\0'; // Null-terminate the string
}

int main() {
    char input[100];
    char binaryStr[9];
    int i;
    char choice;

    do {
        printf("Enter a string: ");
        fgets(input, sizeof(input), stdin);

        printf("ASCII values:\n");
        for (i = 0; input[i] != '\0' && input[i] != '\n'; i++) {
            int asciiValue = (int)input[i];
            intToBinary(asciiValue, binaryStr);
            printf("Character: %c, ASCII (Decimal): %d, ASCII (Binary): %s\n", input[i], asciiValue, binaryStr);
        }

        printf("Do you want to enter another string? (y/n): ");
        scanf(" %c", &choice);
        while (getchar() != '\n'); // Clear the input buffer

    } while (choice == 'y' || choice == 'Y');

    return 0;
}
