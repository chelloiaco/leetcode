#include <cstring>
#include <iostream>

class Solution {
  public:
    int lengthOfLongestSubstring(std::string s) {
        int longest{0};
        int current{0};
        int starting_i{0};
        bool found = false;
        std::string buffer = "";
        for (size_t i{0}; i < s.size(); ++i) {
            found = false;
            for (auto&& b : buffer) {
                if (s.at(i) == b) {
                    ++starting_i;
                    i = starting_i;
                    buffer = s.at(starting_i);
                    found = true;
                    current = 1;
                    break;
                }
            }
            if (!found) {
                buffer += s.at(i);
                ++current;
            }
            if (current > longest) {
                longest = current;
            }
        }

        return longest;
    }
};


int main() {
    Solution sl{};
    std::cout << sl.lengthOfLongestSubstring(" ") << std::endl;
    std::cout << sl.lengthOfLongestSubstring("dvdf") << std::endl;
    std::cout << sl.lengthOfLongestSubstring("abcabcbb") << std::endl;
    std::cout << sl.lengthOfLongestSubstring("bbbbb") << std::endl;
    std::cout << sl.lengthOfLongestSubstring("pwwkew") << std::endl;
}