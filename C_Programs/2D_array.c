//Code to create and print an array
#include <stdio.h>

#define ROW 10
#define COLUMN 100

//Function to store inputs in array and print them
int main() {
    //Array
    char strings[ROW][COLUMN];
    int r = 0;
    int c;
    int i;
//function to receive input from keyboard and store in array
    printf("Enter strings (Press CTRL d to stop):\n");
    while ((i = getchar()) != EOF && r < ROW) {
        if (i == ' ' || i == '\n') {
            strings[r][c] = '\0'; // Null-terminate the
            c = 0;
            r++;
        } else {
            strings[r][c] = i;
            c++;
        }
    }
    strings[r][c] = '\0'; // Null-terminate the last string

    for (int j = 0; j < r; j++) {
        printf("%s\n", strings[j]);
    }
    //function to print the array
    printf("Total inputs: %d\n", r);
    printf("Array: %c\n", strings[r][c]);
    return 0;
}
