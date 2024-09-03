/**
 * 125. Valid Palindrome
 * https://leetcode.com/problems/valid-palindrome
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size();
        while (left < right) {
            char left_char = convert(s[left]);
            if (left_char == '\0') {
                ++left;
                continue;
            }

            char right_char = convert(s[right - 1]);
            if (right_char == '\0') {
                --right;
                continue;
            }

            if (left_char != right_char) {
                return false;
            }

            ++left;
            --right;
        }
        return true;
    }

    char convert(char c) {
        if (c >= 'A' && c <= 'Z') {
            // convert to lower cased
            static_assert('A' < 'a');
            return c + ('a' - 'A');
        } else if (isalnum(c)) {
            return c;
        } else {
            return '\0';
        }
    }
};

int main() {
    print_var(Solution().isPalindrome("A man, a plan, a canal: Panama"));
    print_var(Solution().isPalindrome("race a car"));
    print_var(Solution().isPalindrome(" "));
    print_var(Solution().isPalindrome("0P"));
}
