#include <stdio.h>
int convert(int celcius) {
       int  fahr = (9 * celcius) / 5 + 32;
	return fahr;
}
int main() {
	int i;
	printf("°C\t°F\n");
	while (i <= 100) {
	printf("%d\t%d\n", i,  convert(i));
	i += 10;
    }
    return 0;
}
