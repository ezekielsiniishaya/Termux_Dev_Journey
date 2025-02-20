
// A simple calcultor program with a touch of creativity
// This is a work in progress.

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

// Function to find the index of the operator with the highest precedence
int find_highest_precedence_operator(const std::vector<char> &operators) {
  int highest_precedence_index = -1;
  int highest_precedence = -1;

  // Loop through the operators array
  for (size_t i = 0; i < operators.size(); i++) {
    int precedence = 0;
    if (operators[i] == '*' || operators[i] == '/') {
      precedence = 2; // * and / have higher precedence
    } else if (operators[i] == '+' || operators[i] == '-') {
      precedence = 1; // + and - have lower precedence
    }

    // If this operator has higher precedence, update the highest precedence
    // index
    if (precedence > highest_precedence) {
      highest_precedence = precedence;
      highest_precedence_index = i;
    }
  }

  return highest_precedence_index;
}

// Function to perform calculations based on the arrays of numbers and operators

void perform_operations(std::vector<float> &numbers,
                        std::vector<char> &operators) {

  // Continue performing operations as long as there are operators

  while (!operators.empty()) {
    // Find the operator with the highest precedence
    int highest_precedence_index = find_highest_precedence_operator(operators);

    // Get the numbers and operator at that index
    float num1 = numbers[highest_precedence_index];
    float num2 = numbers[highest_precedence_index + 1];
    char op = operators[highest_precedence_index];

    // Perform the operation
    switch (op) {
    case '+':
      numbers[highest_precedence_index] = num1 + num2;
      break;
    case '-':
      numbers[highest_precedence_index] = num1 - num2;
      break;
    case '*':
      numbers[highest_precedence_index] = num1 * num2;
      break;
    case '/':
      if (num2 != 0) {
        numbers[highest_precedence_index] = num1 / num2;
      } else {
        std::cout << "Error: Division by zero!\n"; // Handle division by zero
        return;
      }
      break;
    default:
      std::cout << "Unknown operator encountered.\n"; // Error handling for
                                                      // unknown operators
      return;
    }

    // Remove the used number and operator
    numbers.erase(numbers.begin() + highest_precedence_index + 1);
    operators.erase(operators.begin() + highest_precedence_index);
  }

  // Output the final result of the calculation
  std::cout << "Result: " << numbers[0] << std::endl;
}

int main() {
  std::string input; // Variable to store the user input
  std::cout
      << "Welcome to eazynote calculator!\nEnter an expression (e.g., "
         "100+222-21/5) and press Enter for result.\nPress Ctrl D (Linux, "
         "MacOs) or Ctrl Z (Windows) to exit.\n";
  while (true) {
    std::vector<float>
        number_array; // Stores the numbers extracted from the input
    std::vector<char>
        operators_array; // Stores the operators extracted from the input

    std::getline(std::cin,
                 input); // Read the entire line of input from the user

    if (std::cin.eof()) { // Check for EOF (Ctrl+D or Ctrl+Z)
      break;              // Exit the loop and terminate the program
    }

    std::string current_number =
        ""; // Temporary string to hold a number as it's being parsed

    // Loop through each character in the input
    for (size_t i = 0; i < input.length(); i++) {
      char current_char = input[i]; // Get the current character

      // If the character is a digit or a decimal point, it is part of a number
      if (current_char == '-' || current_char == '.') {
        current_number +=
            current_char; // Append the character to the current number
      }
      // If the character is an operator, store the current number and the
      // operator
      else if (current_char == ' ') {
        if (!current_number.empty()) { // Only push number if it's not empty
          if (is_number(current_number)) {
            number_array.push_back(std::stof(
                current_number)); // Convert the number to float and store it
            current_number =
                ""; // Reset the temporary number string for the next number
          } else {
            std::cout << "Number is not valid.\n";
          }
        }
      } else if (current_char == '+' || current_char == '-' ||
                 current_char == '*' || current_char == '/') {
        operators_array.push_back(
            current_char); // Store the operator in the function array
      }
      // Ignore any other characters (e.g.,
      // spaces)
    }

    // If there's a number left at the end of the input, store it
    if (!current_number.empty()) {
      if (is_number(current_number)) {
        number_array.push_back(
            std::stof(current_number)); // Convert the final number to float
                                        // and store it
      } else {
        std::cout << "Error: Number is not valid.\n";
      }
    }

    // Check if the input ends with an operator, which is invalid
    if (!number_array.empty() && (input.back() == '+' || input.back() == '-' ||
                                  input.back() == '*' || input.back() == '/')) {
      std::cout << "Error: Expression cannot end with an operator.\n";
      continue; // Skip to the next input if the current one is invalid
    }

    // Perform the operation if there are numbers and operators
    if (number_array.size() > 1) {
      perform_operations(
          number_array,
          operators_array); // Perform the operations and show the result
    } else {
      std::cout << "Error: Invalid input.\n";
    }

    // Reset the arrays for the next input
    number_array.clear();
    operators_array.clear();
  }

  std::cout << "Program terminated.\n"; // Display when the program is
                                        // terminated by EOF
  return 0;                             // Exit the program
}
