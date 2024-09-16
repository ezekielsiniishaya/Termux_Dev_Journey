#include <stdio.h>

#define MAXCOL 5 // The maximum column before folding
#define TABINC 8 // The tab increment size

void print_line(char line[], int length);
int find_last_blank(char line[], int max);
void fold_line(char line[], int len);

int main()
{
    int c, pos = 0;
    char line[MAXCOL + 1];

    while ((c = getchar()) != EOF)
    {
        line[pos] = c;
        if (c == '\n')
        {
            print_line(line, pos);
            pos = 0;
            putchar('\n');
        }
        else if (pos >= MAXCOL)
        {
            fold_line(line, pos);
            pos = 0;
            if (c != ' ' && c != '\t')
            {
                // Start the new line with the current character if it's not a space or tab
                line[pos++] = c;
            }
        }
        else
        {
            pos++;
        }
    }

    return 0;
}

void print_line(char line[], int length)
{
    for (int i = 0; i < length; i++)
    {
        putchar(line[i]);
    }
}

int find_last_blank(char line[], int max)
{
    for (int i = max; i >= 0; i--)
    {
        if (line[i] == ' ' || line[i] == '\t')
        {
            return i;
        }
    }
    return -1;
}

void fold_line(char line[], int len)
{
    int last_blank = find_last_blank(line, len - 1);

    if (last_blank >= 0)
    {
        print_line(line, last_blank);
        putchar('\n');
        print_line(&line[last_blank + 1], len - last_blank - 1);
    }
    else
    {
        print_line(line, len);
        putchar('\n');
    }
}
