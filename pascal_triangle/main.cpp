#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> result;
    // Return empty vector of a vector if no numRows
    if (numRows <= 0) {
      return result;
    }

    for (int i{0}; i < numRows; i++) {
      std::vector<int> internal_vec;

      // Add left side 1
      internal_vec.push_back(1);

      // Add middle
      if (i > 1) {
        for (int j{0}; j < i - 1; j++) {
          int top_left = result.at(i - 1).at(j);
          int top_right = result.at(i - 1).at(j + 1);
          internal_vec.push_back(top_left + top_right);
        }
      }

      // Add right side 1
      if (i != 0) {
        internal_vec.push_back(1);
      }
      result.push_back(internal_vec);
    }
    return result;
  }
};

int main() {
  Solution sl{};
  std::vector<std::vector<int>> result = sl.generate(5);
  std::cout << "[";
  for (size_t i{0}; i < result.size(); ++i) {
    std::cout << "[";
    for (size_t j{0}; j < result.at(i).size(); ++j) {
      std::cout << result.at(i).at(j);
      if (j != result.at(i).size() - 1) {
        std::cout << ",";
      }
    }
    std::cout << "]";
    if (i != result.size() - 1) {
      std::cout << ",";
    }
  }
  std::cout << "]" << std::endl;
}