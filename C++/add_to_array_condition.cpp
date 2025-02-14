
// This program checks if usr input is numbers or characters and add to
// respective arrays
#include <cstdio>
#include <iostream> // Import standard input/output stream (std::cin, std::cout)
#include <string>   // Import string manipulation utilities (std::string class)

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
std::string receive_input() {
  std::string input; // Variable to store the user input
  std::getline(std::cin, input);
  return input;
}

void process_input() {
  std::string input = receive_input();
  std::string current_word = "";

  for (size_t i = 0; i <= input.length(); i++) {

    char current_char = input[i];

    current_word += current_char;
    if (i == input.length() || input[i] == ' ') {
      if (!current_word.empty()) {
        current_word.pop_back();
        if (is_number(current_word)) {
          std::cout << " a number";
        }
        current_word = "";
      }
    }
  }
}
int main() {
  std::cout << "Enter input and press Enter to add to arrays.\nPress Ctrl D "
               "(Linux, "
               "MacOs) or Ctrl Z (Windows) to exit.\n";
  process_input();

  std::cout << "Program terminated\n";
  return 0; // Exit the program
}
