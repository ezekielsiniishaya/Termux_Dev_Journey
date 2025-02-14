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
std::string receive_input() {
  std::string input; // Variable to store the user input
<<<<<<< HEAD
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

=======
  std::getline(std::cin, input);
  return input;
}

void process_input() {
  while (true) {
>>>>>>> 818cd0871f6776e24cbc3ed834cefd84a6e918eb
    if (std::cin.eof()) { // Check for EOF (Ctrl+D or Ctrl+Z)
      break;              // Exit the loop and terminate the program
    }
    std::string input = receive_input(); // variable to store input
    std::string current_word = "";       // variable to store read input without spaces
    std::vector<float> number_array;     // Stores the numbers extracted from the input
    std::vector<char> operators_array;   // Stores the operators extracted from the input

<<<<<<< HEAD
    std::string current_number =
        ""; // Temporary string to hold a number as it's being parsed
=======
    for (size_t i = 0; i <= input.length(); i++) {
>>>>>>> 818cd0871f6776e24cbc3ed834cefd84a6e918eb

      char current_char = input[i];

<<<<<<< HEAD
      // If the character is a digit or a decimal point, it is part of a number
      if (isdigit(current_char) || current_char == '.') {
        current_number +=
            current_char; // Append the character to the current number
      }
      // If the character is an operator, store the current number and the
      // operator
      else if (current_char == '+' || current_char == '-' ||
               current_char == '*' || current_char == '/') {
        if (!current_number.empty()) { // Only push number if it's not empty
          number_array.push_back(std::stof(
              current_number)); // Convert the number to float and store it
          current_number =
              ""; // Reset the temporary number string for the next number
        }
        operators_array.push_back(
            current_char); // Store the operator in the function array
=======
      if (i == input.length() || input[i] == ' ') {
        if (is_number(current_word)) {
          number_array.push_back(std::stof(current_word)); // Convert the number to float and store it
        } else if (current_word == "+" || current_word == "-" || current_word == "*" || current_word == "/") {
          operators_array.push_back(input[i - 1]); // Store the operator in the function array
        } else if (!(std::cin.eof())) {
          std::cout << "Sorry! input, " << current_word
                    << " not a number or operator. Please use spaces to separate numbers and operators " << "\n";
        }
        current_word = "";
>>>>>>> 818cd0871f6776e24cbc3ed834cefd84a6e918eb
      }

<<<<<<< HEAD
    // If there's a number left at the end of the input, store it
    if (!current_number.empty()) {
      number_array.push_back(std::stof(
          current_number)); // Convert the final number to float and store it
=======
      else {
        current_word += current_char;
      }
>>>>>>> 818cd0871f6776e24cbc3ed834cefd84a6e918eb
    }

    // Check if the input ends with an operator, which is invalid
    if (!number_array.empty() && (input.back() == '+' || input.back() == '-' ||
                                  input.back() == '*' || input.back() == '/')) {
      std::cout << "Error: Expression cannot end with an operator.\n";
      continue; // Skip to the next input if the current one is invalid
    } // Check if the input ends with an operator, which is invalid

    // Perform the operation if there are numbers and operators
<<<<<<< HEAD
    if (number_array.size() > 1) {
      perform_operations(
          number_array,
          operators_array); // Perform the operations and show the result
    } else {
      std::cout << "Error: Invalid input, at least one number and operator "
                   "required.\n";
=======
    if (number_array.size() > 1 && operators_array.size() >= 1 && !(number_array.size() == operators_array.size())) {
      perform_operations(number_array, operators_array); // Perform the operations and show the result
    } else if (!(std::cin.eof())) {
      std::cout << "Error: Invalid input, same number of operators and numbers or operators missing.\n";
>>>>>>> 818cd0871f6776e24cbc3ed834cefd84a6e918eb
    }

    // Reset the arrays for the next input
    number_array.clear();
    operators_array.clear();
  }
<<<<<<< HEAD

  std::cout << "Program terminated.\n"; // Display when the program is
                                        // terminated by EOF
  return 0;                             // Exit the program
=======
}

int main() {
  std::cout << "Welcome to eazynote calculator!\nEnter an expression (e.g., "
               "100+222-21/5) and press Enter for result. Use spaces to separate numbers from operators\nPress Ctrl D "
               "(Linux, "
               "MacOs) or Ctrl Z (Windows) to exit.\n";

  process_input();

  std::cout << "GoodBye!\n";
  return 0; // Exit the program
>>>>>>> 818cd0871f6776e24cbc3ed834cefd84a6e918eb
}
