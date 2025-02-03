#include <stdio.h>

int main() {
    int a, b;
    printf("Enter a number: \n");
    a = getchar();
    printf("Enter secknd number: \n");
    b = getchar();
    int result = a + b;
    printf("%d + %d = %d \n", a, b, result);
}
