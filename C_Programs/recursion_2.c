#include <stdio.h>

// Function to calculate factorial
int factorial(int n)
{
    // Base case: if n is 0, factorial is 1

    // Recursive case: n! = n * (n-1)!
    int result;
    if (n > 0)
    {
        result = n + factorial(n - 1);
        printf("%d\n", result);
    }
    else
    {
        result = 0;
    }
    return result;
}

int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    factorial(number);

    return 0;
}
