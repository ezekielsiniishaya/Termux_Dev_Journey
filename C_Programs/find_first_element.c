#include <stdio.h>
#define MAX_ROWS 1000
#define MAX_COLUMNS 1000

int find_first_element(int array[][MAX_COLUMNS], int row)
{
    for (int i = 0; i < row; i++)
    {
        int column = 0;

        if (array[i][column] != ' ' && array[row][column] != '\t')
        {
            return array[i][column];
        }
        return -1;
    }
}
int main()
{
    int array_2D[MAX_ROWS][MAX_COLUMNS]; // 2D array to store code input
    int row, column;
    int exit_status = 0;
    // Prompt the user to enter lines of code
    printf(
        "Enter %d lines of code (each line up to %d characters). All "
        "comments will be cleared:\n",
        MAX_ROWS, MAX_COLUMNS - 1);
    for (row = 0; row < MAX_ROWS; row++)
    {
        column = 0;
        while (column < MAX_COLUMNS - 1)
        {
            int character = getchar();
            if (character == EOF)
            {
                exit_status = 1;
                break;
            }
            if (character == '\n')
            {
                break;
            }
            array_2D[row][column++] = character;
        }
        array_2D[row][column] = '\0'; // Null-terminate the string
        if (exit_status == 1)
        {
            break;
        }
    }
    int element = find_first_element(array_2D, 0);
    putchar(element);
}