#include <stdio.h>

#define ROW 10
#define COLUMN 100

int main() {
    char strings[ROW][COLUMN];
    char longStrings[ROW][COLUMN];
    int r = 0;
    int c;
    int i;
    int longIndex = 0;

    printf("Enter strings (Press CTRL+d to stop):\n");
    while ((i = getchar()) != EOF && r < ROW) {
        if (i == ' ' || i == '\n') {
            strings[r][c] = '\0';
            c = 0;
            r++;
        } else {
            strings[r][c] = i;
            c++;
        }
    }
    strings[r][c] = '\0';

    printf("All inputs:\n");
    for (int j = 0; j <= r; j++) {
        printf("%s\n", strings[j]);
    }

    return 0;
}
