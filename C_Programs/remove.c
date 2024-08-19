//code to remove space, tabs ans new lines from inputs
#include <stdio.h>

#define MAXLEN 100
//functions
void get_char(char array_1[]);
void edit_char(char array_1[], char array_2[]);
void print_char(char array_2[]);

int main() {
    //array to store inputs
    char array_1[MAXLEN];
    //array to store modified inputs
    char array_2[MAXLEN];
    int c;
    //calling all functions in main function for execution
    while ((c = getchar()) != EOF) {
        get_char(array_1);
        edit_char(array_1, array_2);
        print_char(array_2);
    }

    return 0;
}

// Get characters from stdin and store in array_1[]
void get_char(char array_1[]) {
    int i = 0;
    int c;

    while ((c = getchar()) != EOF) {
        array_1[i++] = c;
    }
    array_1[i] = '\0'; // Null-terminate the string
}

// Edit characters in array_1[], remove spaces, tabs, and newlines, and store in array_2[]
void edit_char(char array_1[], char array_2[]) {
    int i = 0;
    int j = 0;

    while (array_1[i] != '\0') {
        if (array_1[i] != ' ' && array_1[i] != '\t' && array_1[i] != '\n') {
            array_2[j++] = array_1[i];
        }
        i++;
    }
    array_2[j] = '\0'; // Null-terminate the string
}

// Print characters in array_2[]
void print_char(char array_2[]) {
    printf("%s\n", array_2);
}
