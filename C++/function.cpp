#include <iostream>
#include <string>

// Function to check if a string is a valid number (integer or floating-point)
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
  std::string input;
  std::cout << "Enter a value: ";
  std::cin >> input;

  if (is_number(input)) {
    std::cout << input << " is a number." << std::endl;
  } else if (input.length() == 1 || input == "+" ||
             input == "-") { // Single character or just + or -
    std::cout << input << " is a character." << std::endl;
  } else {
    std::cout << input << " is neither a valid number nor a single character."
              << std::endl;
  }

  return 0;
}
