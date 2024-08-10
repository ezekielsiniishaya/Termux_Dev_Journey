#include <stdio.h>

int main() {
    int c, blank = 0;

    while ((c = getchar()) != EOF) {
	    if (c == ' ') {
		if (blank == 0) {
                  putchar(c);
	          blank = 1;
                }
	    }
	    else {
	      putchar(c);
	      blank = 0;
	}
    }

    return 0;
}
