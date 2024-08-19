//code to print the reverse of input characters
#include <stdio.h>

int main() {
    printf("Enter text (Ctrl+D to exit):\n");
    
    int c;
    int array[1000]; // Buffer to store characters
    int row = 0; // Index for buffer
//receiving input
    while ((c = getchar()) != EOF) {
        if (c == '\n') { // End of line
            // Print reversed line
            for (int i = row; i >= 0; i--) {
                  printf("%c", array[i]);                         }
        printf("\n");
        row = 0;//terminate index
        } 
        else{
            array[row++] = c; // Store in buffer
        }
        array[row] = '\0';//terminate buffer
    }
    return 0;
}

