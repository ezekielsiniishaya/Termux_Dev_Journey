//Code to save input as strings to two arrays, first in a main array then copying to a second array
#include <stdio.h>

#define ROW 10
#define COLUMN 100

int main() {
    //main array
    char strings[ROW][COLUMN];
    //second array to store strings longer than 5
    char longStrings[ROW][COLUMN];
    int r = 0;
    int c = 0;
    int i;
    int l = 0;

    printf("Enter strings (Press CTRL+d to stop):\n");
    while ((i = getchar()) != EOF && r < ROW) {
        if (i == ' ' || i == '\n') {
            strings[r][c] = '\0';  // Null-terminate the current string
            
            if (c > 5) {
                // If the string length is greater than 5, copy it to longStrings before EOF
                for (int k = 0; k <= c; k++) {
                    longStrings[l][k] = strings[r][k];
                }
                l++;
            }
            r++;
            c = 0;
        } else {
            strings[r][c] = i;
            c++;
        }

    }
    
    
    //copying strings longer than 5 to longStrings after EOF is reached
    if (c > 5) {
        for (int k = 0; k <= c; k++) {
            longStrings[l][k] = strings[r][k];
        }
        l++;
    }
    
    // Null-terminate the last string (in case of EOF without newli    ne)
    strings[r][c] = '\0';
    printf("Inputs longer than 5 characters:\n");
    for (int j = 0; j < l; j++) {
        printf("%s\n", longStrings[j]);
    }

    return 0;
}

