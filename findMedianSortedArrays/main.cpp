#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
  public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        // Combine arrays and sort
        std::vector<int> allNums(nums1);
        allNums.insert(allNums.end(), nums2.begin(), nums2.end());
        std::sort(allNums.begin(), allNums.end());
        int medianIndex = (allNums.size() - 1) / 2;

        if (allNums.size() % 2) {
            // odd length
            return allNums.at(medianIndex);
        } else {
            // even length
            return (float)(allNums.at(medianIndex) + allNums.at(medianIndex + 1)) / 2;
        }
    }
};

int main() {
    Solution sl{};
    std::vector<int> nums1 = {1, 2};
    std::vector<int> nums2 = {3, 4};
    std::cout << sl.findMedianSortedArrays(nums1, nums2) << std::endl;
}