#include <iomanip>
#include <iostream>
#include <ostream>
using std::fixed;
using std::setprecision;
using namespace std;
const int SENTINEL = -1;

int main() {
  int total, grade, gradeCounter, average;
  total = 0;
  gradeCounter = 0;
  cout << "Enter Grade: " << SENTINEL << "To the end" << endl;
  cin >> grade;
  while (grade != SENTINEL) {
    total = total + grade;
    gradeCounter++;
    cout << "Enter grade " << SENTINEL << endl;
    cin >> grade;
  }
  cout << "Class Average = " << setprecision(2) << fixed << average << endl;
  return 0;
}
