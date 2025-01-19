#include <stdio.h>

// Define the maximum number of lines and maximum line length
#define MAX_LINES 1000
#define MAX_LINE_LENGTH 1000

// Function to find the starting index of a comment ('//') in a single line
int find_comment(char *line)
{
    for (int j = 0; line[j] != '\0'; j++)
    {
        if (line[j] == '/' && line[j + 1] == '/')
        {
            return j; // Return the starting index of the comment
        }
    }
    return -1; // Return -1 if no comment is found
}

// Function to remove comments from all lines
void remove_comments(char array[][MAX_LINE_LENGTH], int line_count)
{
    for (int i = 0; i < line_count; i++)
    {
        int comment_start = find_comment(array[i]); // Check for comments in each line
        if (comment_start != -1)
        {
            array[i][comment_start] = '\0'; // Null-terminate the string at the start of the comment
        }
    }
}

// Function to print the 2D array of code lines
void print_line(char array[][MAX_LINE_LENGTH], int line_count)
{
    for (int i = 0; i < line_count; i++)
    {
        printf("%s\n", array[i]); // Print each line
    }
}

int main()
{
    char array[MAX_LINES][MAX_LINE_LENGTH]; // 2D array to store lines
    int line = 0;                           // Current line index
    int column = 0;                         // Current column index
    char c;

    printf("Enter code lines to remove comments (Ctrl+D to end on Linux/Mac or Ctrl+Z on Windows):\n");

    // Read characters until EOF
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            array[line][column] = '\0'; // Null-terminate the current line
            line++;                     // Move to the next line
            column = 0;                 // Reset column for the new line

            // Check if the maximum number of lines is reached
            if (line >= MAX_LINES)
            {
                printf("Maximum number of lines reached. Stopping input.\n");
                break;
            }
        }
        else
        {
            // Store the character in the current line
            if (column < MAX_LINE_LENGTH - 1)
            {
                array[line][column++] = c;
            }
            else
            {
                printf("Line length exceeded. Moving to the next line.\n");
                array[line][column] = '\0'; // Null-terminate the current line
                line++;                     // Move to the next line
                column = 0;                 // Reset column
                if (line >= MAX_LINES)
                {
                    printf("Maximum number of lines reached. Stopping input.\n");
                    break;
                }
            }
        }
    }

    // Null-terminate the last line in case EOF ends without a newline
    if (column > 0)
    {
        array[line][column] = '\0';
        line++;
    }

    // Print the code before removing comments
    printf("\nBefore Removing Comments:\n");
    print_line(array, line);

    // Remove comments from the code
    remove_comments(array, line);

    // Print the code after removing comments
    printf("\nAfter Removing Comments:\n");
    print_line(array, line);

    return 0;
}
