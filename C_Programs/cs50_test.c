#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string s = get_string("Name: ");
    printf("Hello, %s\n", s);
    return 0;
}

