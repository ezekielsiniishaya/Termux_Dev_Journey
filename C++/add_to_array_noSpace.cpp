
#include <iostream> // Import standard input/output stream (std::cin, std::cout)
#include <string>   // Import string manipulation utilities (std::string class)
std::string receive_input() {
  std::string input; // Variable to store the user input
  std::getline(std::cin, input);
  return input;
}
void process_input() {
  while (true) {
    if (std::cin.eof()) { // Check for EOF (Ctrl+D or Ctrl+Z)
      break;              // Exit the loop and terminate the program
    }
    std::string input = receive_input(); // variable to store input
    std::string current_word =
        ""; // variable to store read input without spaces
    for (size_t i = 0; i <= input.length(); i++) {
      char current_char = input[i];

      if (i == input.length() || current_char == '-' || current_char == '+' ||
          current_char == '*' || current_char == '/') {
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
        } else {
          std::cout << "number " << current_word << "\n";
          if (i != input.length()) {
            std::cout << "operator " << current_char << "\n";
          }
          current_word = "";
        }
      } else {
        current_word += current_char;
      }
    }
  }
}

int main() {
  std::cout << "Welcome to eazynote calculator!\nEnter an expression (e.g., "
               "100+222-21/5) and press Enter for result. Use spaces to "
               "separate numbers from operators\nPress Ctrl D "
               "(Linux, "
               "MacOs) or Ctrl Z (Windows) to exit.\n";

  process_input();

  std::cout << "GoodBye!\n";
  return 0; // Exit the program
}
