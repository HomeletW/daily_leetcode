/**
 * 20. Valid Parentheses
 * https://leetcode.com/problems/valid-parentheses
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for (char c: s) {
            if (c == '(') {
                stack.push_back(')');
            } else if (c == '{') {
                stack.push_back('}');
            } else if (c == '[') {
                stack.push_back(']');
            } else {
                if (stack.empty()) {
                    return false;
                }
                if (stack.back() == c) {
                    stack.pop_back();
                } else {
                    return false;
                }
            }
        }
        return stack.empty();
    }
};

int main() {
    print_line(Solution().isValid("()[]{}"));
    print_line(Solution().isValid("[()[]{}{}]"));
    print_line(Solution().isValid("["));
    print_line(Solution().isValid("]"));
    print_line(Solution().isValid(""));
}