//Program to replace tabs with the proper number of spaces
#include<stdio.h>
//works for TAB_WIDTH of 4 or 8
#define TAB_WIDTH 8
//function to print blanks to replace tabs
void add_spaces(int num_spaces) {
    for(int i = 0; i < num_spaces; i++) {
        putchar(' ');
    }
}

int main() {
    int c, pos = 0, spaces;
    //Reading characters and calling add_space function when tab is encountered
    while((c = getchar()) != EOF) {
        if (c == '\t') {
            spaces = TAB_WIDTH - (pos % TAB_WIDTH);
            add_spaces(spaces);
            pos += spaces;
        }
        //printing newline and resetting line position(pos) to 0
        else if (c == '\n') {
            putchar(c);
            pos = 0;
        }
        //Printing characters 
        else {
            putchar(c);
            pos++;
        }
    }
    return 0;
}
