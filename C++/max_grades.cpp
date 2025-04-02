#include <iostream>
#include <ostream>
using namespace std;
const int MAX_GRADES = 10; // Maximum grade

int main() {
  int total, grade, gradeCounter, average;
  total = 0;
  gradeCounter = 0;
  while (gradeCounter < MAX_GRADES) {
    cout << "Enter Grade" << endl;
    cin >> grade;
    total = total + grade;
    gradeCounter++;
  }
  average = total / MAX_GRADES;
  cout << "Class average = " << average << endl;
  return 0;
}
