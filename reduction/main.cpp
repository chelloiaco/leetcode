#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
  public:
    int reductionOperations(std::vector<int>& nums) {
        // If it's of length 1, return 0 operations
        if (nums.size() == 1) {
            return 0;
        }

        int result{0};
        int operations{0};
        std::sort(nums.begin(), nums.end());
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums.at(i) != nums.at(i - 1)) {
                ++operations;
            }
            result += operations;
        }

        return result;
    }
};


int main() {
    Solution sl{};
    std::vector<std::vector<int>> numstests = {
        {5, 1, 3},
        {1, 1, 1},
        {1, 1, 2, 2, 3}};
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