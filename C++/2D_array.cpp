#include <iostream>
using namespace std;

int main()
{
	const int rows = 1; // Number of rows
	const int cols = 4; // Number of columns

	float array[rows][cols]; // Declare a 2D array

	// Input values from the console
	cout << "Enter " << rows * cols << " integers for the 2D array:" << endl;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cout << "Enter value for array[" << i << "][" << j << "]: ";
			cin >> array[i][j]; // Read input into the array
		}
	}

	// Output the 2D array to verify the input
	cout << "\nThe 2D array you entered is:" << endl;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cout << array[i][j] << " ";
		}
		cout << endl; // Move to the next row
	}

	return 0;
}
/*
#include <iostream>
using namespace std;

int main() {
  // Declare and initialize a 2D array
  int array[3][4] = {{100, 2, 300000, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

  // Access and print elements
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 4; ++j) {
      cout << "array[" << i << "][" << j << "] = " << array[i][j] << endl;
    }
  }

  return 0;
}
*/
