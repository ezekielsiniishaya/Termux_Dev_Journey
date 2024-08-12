//Code to save input as strings to two arrays simultaneously.
#include <stdio.h>

#define ROW 10
#define COLUMN 100

int main() {
    //This array stores all inputs
    char strings[ROW][COLUMN];
    //This arrays store inputs longer that 5 strings
    char longStrings[ROW][COLUMN];
    int r = 0;
    int c = 0;
    int i;
    int l = 0;
    //receiving character input from user and saving as strings to arrays
    printf("Enter strings (Press CTRL+d to stop):\n");
    while ((i = getchar()) != EOF && r < ROW) {
        if (i == ' ' || i == '\n') {
            longStrings[l][c] = '\0';
            if (c > 5) {
                l++;
            }
          strings[r][c] = '\0';
          r++;
          c = 0;
        } else {
            longStrings[l][c] = i;
            strings[r][c] = i;
            c++;
        }
    }
    longStrings[l][c] = '\0';
    strings[r][c] = '\0';
    printf("All inputs:\n");
    for (int a = 0; a < r; a++) {
        printf("%s\n", strings[a]);
    }
    printf("Inputs longer than 5 strings:\n");
    for (int j = 0; j <= l; j++) {
        printf("%s\n", longStrings[j]);
    }

    return 0;
}
