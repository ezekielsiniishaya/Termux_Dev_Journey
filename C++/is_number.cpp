
// This program checks if usr input is numbers or characters
#include <cstdio>
#include <iostream> // Import standard input/output stream (std::cin, std::cout)
#include <string>   // Import string manipulation utilities (std::string class)
#include <vector> // Import dynamic array functionality (std::vector container)

/* Function to check if the input string is a valid number (including decimals)
  - Here, input is passed by reference, so we don't copy the entire string.
  - The string can't be modified because it's passed as const.
*/

bool is_number(const std::string &input) {
  if (input.empty() || input == "+" || input == "-")
    return false; // + and - alone are characters

  size_t start =
      (input[0] == '+' || input[0] == '-') ? 1 : 0; // Handle optional sign
  bool hasDecimal = false; // To track if a decimal point is present

  for (size_t i = start; i < input.length(); i++) {
    if (input[i] == '.') {
      if (hasDecimal)
        return false;    // More than one decimal point is invalid
      hasDecimal = true; // Mark that we have encountered a decimal
    } else if (input[i] < '0' || input[i] > '9') {
      return false; // Any non-numeric character (except one '.') makes it
                    // invalid
    }
  }

  return true; // It's a valid number
}

int main() {
  std::string input; // Variable to store the user input
  std::cout
      << "Enter input and press Enter to add to arrays.\nPress Ctrl D (Linux, "
         "MacOs) or Ctrl Z (Windows) to exit.\n";
  while (true) {
    std::vector<float>
        number_array; // Stores the numbers extracted from the input
    std::vector<char>
        operators_array; // Stores the operators extracted from the input

    std::getline(std::cin,
                 input); // Read the entire line of input from the user
    // std::cout << "input is " << input;
    if (std::cin.eof()) { // Check for EOF (Ctrl+D or Ctrl+Z)
      break;              // Exit the loop and terminate the program
    }

    std::string current_number =
        ""; // Temporary string to hold a number as it's being parsed
            // std::cout << "\nadding to current_number\n";
    // Loop through each character in the input
    for (size_t i = 0; i < input.length(); i++) {
      char current_char = input[i]; // Get the current character

      // If the character is a digit or a decimal point, it is part of a number

      current_number +=
          current_char; // Append the character to the current number
    }
    // std::cout << "current_number is " << current_number;
    // std::cout << "\n";
    if (is_number(current_number)) {
      std::cout << "You entered number\n";
    } else {
      std::cout << "You entered characters\n";
    }
  }
  std::cout << "Program terminated\n";
  return 0; // Exit the program
}
