#include <stdio.h>

char array[5];
int i = 0;

int main()
{
    int c = getchar();
    while (c != EOF && i < 5)
    {
        array[i] = c;
        i++;
        c = getchar();
    }
    for (int j = 0; j < i; j++)
    {
        printf("%c", array[j]);
    }
    return 0;
}
