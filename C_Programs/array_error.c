#include <stdio.h>

int main() {
    int array[4096] = {0};
    array[7000] = 0;
    printf("%d\n", array[7000]);
}
