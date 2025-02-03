#include <stdio.h>

int main() {
    // File reading
    FILE *file = fopen("commands.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    int c;  // Change char to int
    while ((c = fgetc(file)) != EOF) {
        printf("%c", (char)c);  // Cast to char for printing
    }
    fclose(file);

    // Input streams (user input)
    printf("Enter text (Ctrl+D to end): ");
    while ((c = getchar()) != EOF) {
        printf("%c", (char)c);  // Cast to char for printing
    }

    // Error handling
    file = fopen("nonexistent.txt", "r");
    if (file == NULL) {
        printf("Error opening file (EOF): %d\n", EOF);
    } else {
        fclose(file);
    }

    return 0;
}
