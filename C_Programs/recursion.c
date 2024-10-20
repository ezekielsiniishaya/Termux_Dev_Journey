#include <stdio.h>

// Function to calculate factorial
int factorial(int n)
{
    // Base case: if n is 0, factorial is 1
    if (n == 0)
    {
        return 1;
    }
    // Recursive case: n! = n * (n-1)!
    else
    {
        return n * factorial(n - 1);
    }
}

int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    // Calculate factorial using the recursive function
    int result = factorial(number);
    printf("Factorial of %d is %d\n", number, result);

    return 0;
}
