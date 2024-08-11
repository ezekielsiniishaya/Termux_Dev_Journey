#include <stdio.h>

int main() {
    FILE *file;
    char ch;

    file = fopen("file.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file\n");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
    return 0;
}
#include <stdio.h>

// Function to calculate factorial
unsigned long long factorial(int n) {
  if (n < 0) {
    return 0; // Factorial of a negative number is not defined
  }
  unsigned long long fact = 1;
  for (int i = 1; i <= n; ++i) {
    fact *= i;
  }
  return fact;
}

int main() {
  int number;

  // Ask the user for a number
  printf("Enter a positive integer: ");
  scanf("%d", &number);

  // Calculate factorial
  unsigned long long result = factorial(number);

  // Print the result
  if (number < 0) {
    printf("Factorial of a negative number is not defined.\n");
  } else {
    printf("Factorial of %d is %llu\n", number, result);
  }

  return 0;
}
