#include <stdio.h>

int main() {
    int c;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            putchar('\\');
            putchar('b');
        }
	else if (c == '\\') {
		putchar('\\');
		putchar('\\');
	}
	else if (c == '\t') {
		putchar('\\');
		putchar('t');
	}
	else {
	putchar(c);
	}
    }

    return 0;
}
