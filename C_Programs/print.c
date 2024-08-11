#include <stdio.h>
 #define IN 1 /* inside a word */
 #define OUT 0 /* outside a word */
 /* count lines, words, and characters in input */
 int main()
 {
 int c, nl, nw, nc, state;
 state = OUT;
 nl = nw = nc = 0;
 while ((c = getchar()) != EOF) {
	 putchar(c);
	 putchar('\n');

}
}
