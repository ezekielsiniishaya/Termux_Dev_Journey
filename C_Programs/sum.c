#include <stdio.h>

int main() {
    int num1, num2, num3;
    char operation1;
    char operation2;

    // Asking for user input
    printf("Enter the first number: ");
    scanf("%d", &num1);
    
    // To consume the newline left by previous scanf
    getchar();

    printf("Enter first operation: ");
    scanf(" %c", &operation1);

    printf("Enter the second number: ");
    scanf("%d", &num2);
    
    // To consume the newline left by previous scanf
    getchar();

    printf("Enter second operation: ");
    scanf(" %c", &operation2);

    printf("Enter the third number: ");
    scanf("%d", &num3);

    // You can now proceed with your calculations here

    // Displaying the result
    return 0;
}

