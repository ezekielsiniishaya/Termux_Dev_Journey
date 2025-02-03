#include<stdio.h>

#define ROW 10
#define COLUMN 50
//Array to store input as characters
char strings[ROW];
int r = 0, i;

int main(void) {
    while((i = getchar()) != EOF && r < ROW) {
                strings[r] = '\0';
                strings[r] = i;
                r++;
    }
    strings[r] = '\0';
    for (int j = 0; j <= r; j++) {
        printf("%c", strings[j]);
    }
}

