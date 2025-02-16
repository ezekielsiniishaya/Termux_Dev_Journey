
// A simple calcultor program with a touch of creativity

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
std::string receive_input() {
  std::string input; // Variable to store the user input
  std::getline(std::cin, input);
  return input;
}
/* This function process the entire line of input, separating numbers from
 * operators and validates the input*/

void process_input() {
  while (true) {
    if (std::cin.eof()) { // Check for EOF (Ctrl+D or Ctrl+Z)
      break;              // Exit the loop and terminate the program
    }
    std::vector<float>
        number_array; // Stores the numbers extracted from the input
    std::vector<char>
        operators_array; // Stores the operators extracted from the input
    std::string input = receive_input(); // variable to store input
    std::string current_word =
        "";        // variable to store read input without spaces
    int error = 0; // check for error in input before calculation
    for (size_t i = 0; i <= input.length(); i++) {
      char current_char = input[i];
      // Separation begins when an operator is encountered but only if the
      // operator does not belong to a signed number
      if (current_char == ' ') {
        std::cout << "Please do not use spaces\n";
        break;
      } else if (i == input.length() || current_char == '-' ||
                 current_char == '+' || current_char == '*' ||
                 current_char == '/') {
        if ((i == 0) || ((current_char == '-' || current_char == '+') &&
                         (input[i - 1] == '+' || input[i - 1] == '-' ||
                          input[i - 1] == '*' || input[i - 1] == '/'))) {
          current_word += current_char;
          continue;
        } else if ((current_char == '*' || current_char == '/') &&
                   (input[i - 1] == '-' || input[i - 1] == '+' ||
                    input[i - 1] == '*' || input[i - 1] == '/')) {
          std::cout << "wrong operator arrangement " << input[i - 1] << " "
                    << input[i] << "\n";
          error = 1;
        } else if (input.back() == '+' || input.back() == '-' ||
                   input.back() == '*' || input.back() == '/') {
          std::cout
              << "Error: Expression cannot end with an operator.\n"; // Skip to
                                                                     // the next
                                                                     // input if
                                                                     // the
                                                                     // current
                                                                     // one is
          error = 1;
          break;
        } else {

          if (is_number(current_word)) {
            number_array.push_back(std::stof(
                current_word)); // Convert the number to float and store it
          } else {
            std::cout << "invalid number " << current_word << "\n";
            error = 1;
            break;
          }
          if (i != input.length()) {
            if (current_char == '+' || current_char == '-' ||
                current_char == '*' || current_char == '/') {
              operators_array.push_back(current_char);
              // std::cout << "operator " << current_char << "\n";
            }
          }
          current_word = "";
        }
      } else {
        current_word += current_char;
      }
    }

    // Perform the operation if there are numbers and operators
    if ((number_array.size() > operators_array.size()) && error != 1) {

      perform_operations(
          number_array,
          operators_array); // Perform the operations and show the result

    } else if (!(std::cin.eof()) && error != 1) {
      std::cout << "Error: Invalid input.";
    }

    // Reset the arrays for the next input
    number_array.clear();
    operators_array.clear();
  }
}

int main() {
  std::cout << "Welcome to eazynote calculator!\nEnter an expression (e.g., "
               "100+222-21/5) and press Enter for result.\nPlease do not use "
               "spaces.\nPress Ctrl D "
               "(Linux, "
               "MacOs) or Ctrl Z (Windows) to exit.\n";

  process_input();

  std::cout << "GoodBye!\n";
  return 0; // Exit the program
}
