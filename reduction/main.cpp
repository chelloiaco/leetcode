#include <algorithm>
#include <iostream>
#include <limits.h>
#include <vector>

class Solution {
public:
  int reductionOperations(std::vector<int>& nums) {
    // If it's of length 1, return 0 operations
    if (nums.size() == 1) {
      return 0;
    }

    int largest{INT_MIN};
    int largest_i{0};
    int nextLargest{INT_MIN};
    int operations{0};
    bool allEqual{true};
    std::sort(nums.begin(), nums.end());
    do {
      // Check if all equal
      allEqual = true;
      for (size_t i = 0; i < nums.size() - 1; i++) {
        if (nums.at(i) != nums.at(i + 1)) {
          allEqual = false;
          break;
        }
      }
      if (allEqual) {
        break;
      }

      // Find largest
      for (size_t i = nums.size() - 1; i > 0; i--) {
        if (nums.at(i) > nums.at(i - 1)) {
          largest = nums.at(i);
          largest_i = i;
          break;
        }
      }
      nextLargest = nums.at(largest_i - 1);

      // Reduce
      nums.at(largest_i) = nextLargest;
      operations++;
    } while (!allEqual);

    return operations;
  }
};


int main() {
  Solution sl{};
  std::vector<std::vector<int>> numstests = {
      {5, 1, 3},
      {1, 1, 1},
      {1, 1, 2, 3, 3}};
  for (auto&& nums : numstests) {
    int result = sl.reductionOperations(nums);

    // print tests
    std::cout << "{";
    for (size_t i = 0; i < nums.size(); i++) {
      std::cout << nums.at(i);
      if (i < nums.size() - 1) {
        std::cout << ", ";
      }
    }
    std::cout << "} = " << result << std::endl;
  }
}