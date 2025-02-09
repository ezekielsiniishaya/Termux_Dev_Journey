// A program to receive input from the console and save it to an array

// Headers for input/output operations
#include <iostream>

// Global decalaration of std
using namespace std;

// Constant to store max input allowed
const int MAX_SIZE = 100;

// One dimensional array to store input from the console
char inputArray[MAX_SIZE];

// Main function, entry point of the program
int main()
{
	char ch;       // variable to store input characters
	int index = 0; // variable to store the number of characters in the array
		       // Welcome message on the console prompting the user for input
	cout << "Enter characters (press Enter to finish): ";

	// Read characters until newline or array is full
	while (cin.get(ch) && ch != '\n' && index < MAX_SIZE - 1) {
		inputArray[index] = ch;
		index++;
	}

	// Null-terminate the array to make it a valid C-string
	inputArray[index] = '\0';

	cout << "You entered: " << inputArray << endl;

	return 0;
}
