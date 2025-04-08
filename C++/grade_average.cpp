#include <iostream>
using namespace std;

int main() {
  float total = 0;
  int grade_counter = 0;
  float add = 0;
  while (grade_counter < 10) {
    cout << "Input next grade" << endl;
    cin >> add;
    grade_counter++;
    total = total + add;
  }
  float average = total / 10;
  cout << "The average is " << average << endl;
  return 0;
}
