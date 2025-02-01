#include <stdio.h>

int main(void)
{ // Use 'void' if no arguments are needed
    int ch;

    printf("Press Enter: ");
    ch = getchar(); // Reads one character

    if (ch == '\n')
    {
        printf("You pressed Enter (LF detected).\n");
    }
    else if (ch == '\r')
    {
        printf("Carriage return detected.\n");
        // Consume the '\n' if running on Windows
        if (getchar() == '\n')
        {
            printf("Line feed also detected (Windows-style Enter).\n");
        }
    }
    else
    {
        printf("You entered: %c\n", ch);
    }

    return 0;
}
