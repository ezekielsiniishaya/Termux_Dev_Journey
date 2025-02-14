#include <cstddef>
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

  size_t start = (input[0] == '+' || input[0] == '-') ? 1 : 0; // Handle optional sign
  bool hasDecimal = false;                                     // To track if a decimal point is present

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
  std::string input = receive_input(); // variable to store input
  std::string current_word = "";       // variable to store read input without spaces
  std::vector<float> number_array;     // Stores the numbers extracted from the input
  std::vector<char> operators_array;   // Stores the operators extracted from the input

  for (size_t i = 0; i <= input.length(); i++) {

    char current_char = input[i];

    if (i == input.length() || input[i] == ' ') {
      if (is_number(current_word)) {
        std::cout << " a number " << current_word << "\n";
        number_array.push_back(std::stof(current_word)); // Convert the number to float and store it
      } else if (current_word == "+" || current_word == "-" || current_word == "*" || current_word == "/") {
        operators_array.push_back(input[i - 1]); // Store the operator in the function array
        std::cout << "not number " << current_word << "\n";
      } else {
        std::cout << "input, " << current_word << " not word or character " << "\n";
      }
      current_word = "";
    }

    else {
      current_word += current_char;
    }
  }
  for (size_t i = 0; i < number_array.size(); i++) {

    std::cout << "number " << i << " in array " << number_array[i] << "\n";
  }
  for (size_t i = 0; i < operators_array.size(); i++) {

    std::cout << "operator " << i << " in array " << operators_array[i] << "\n";
  }
}

int main() {
  std::cout << "Enter input and press Enter to add to arrays.\nPress Ctrl D "
               "(Linux, "
               "MacOs) or Ctrl Z (Windows) to exit.\n";
  while (true) {
    if (std::cin.eof()) { // Check for EOF (Ctrl+D or Ctrl+Z)
      break;              // Exit the loop and terminate the program
    }
    process_input();
  }
  std::cout << "Program terminated\n";
  return 0; // Exit the program
}
