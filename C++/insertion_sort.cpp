#include <iostream>
#include <vector>

// Swap two pairs
void swapPairs(std::pair<float, float> &a, std::pair<float, float> &b) {
  std::pair<float, float> temp = a;
  a = b;
  b = temp;
}

// Insertion sort on vector of pairs based on the first element
void insertionSortVector(std::vector<std::pair<float, float>> &arr) {
  for (int i = 1; i < arr.size(); i++) {
    int j = i;
    while (j > 0 && arr[j].first < arr[j - 1].first) {
      swapPairs(arr[j], arr[j - 1]);
      j--;
    }
  }
}

// Print function
void printVector(const std::vector<std::pair<float, float>> &arr) {
  for (const auto &p : arr) {
    std::cout << "(" << p.first << ", " << p.second << ") ";
  }
  std::cout << "\n";
}

int main() {
  std::vector<std::pair<float, float>> arr = {{3, 4}, {3, 9},  {2, 3},
                                              {1, 2}, {7, 10}, {10, 12},
                                              {6, 9}, {1, 4},  {5, 8}};

  std::cout << "Before sorting:\n";
  printVector(arr);

  insertionSortVector(arr);

  std::cout << "After sorting:\n";
  printVector(arr);

  return 0;
}
