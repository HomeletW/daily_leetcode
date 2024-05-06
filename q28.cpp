/**
 * 28. Find the Index of the First Occurrence in a String
 * https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size()) {
            return -1;
        }
        for (int i = 0; i < haystack.size() - needle.size() + 1; ++i) {
            bool found = true;
            for (int j = 0; j < needle.size(); ++j) {
                if (haystack[i + j] != needle[j]) {
                    found = false;
                    break;
                }
            }
            if (found) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    print_line(Solution().strStr("sadbutsad", "sad"));
    print_line(Solution().strStr("123", "sad"));
    print_line(Solution().strStr("abcabcdd", "bc"));
    print_line(Solution().strStr("abcabcdd", "dd"));
    print_line(Solution().strStr("abcabcdd", "ddd"));
    print_line(Solution().strStr("a", "ddd"));
}