/**
 * 150. Evaluate Reverse Polish Notation
 * https://leetcode.com/problems/evaluate-reverse-polish-notation
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        vector<int> stack{};

        for (int i = 0; i < tokens.size(); ++i) {
            const string &token = tokens[i];
            if (token == "+") {
                int rhs = stack.back();
                stack.pop_back();
                int lhs = stack.back();
                stack.pop_back();
                stack.push_back(lhs + rhs);
            } else if (token == "-") {
                int rhs = stack.back();
                stack.pop_back();
                int lhs = stack.back();
                stack.pop_back();
                stack.push_back(lhs - rhs);
            } else if (token == "*") {
                int rhs = stack.back();
                stack.pop_back();
                int lhs = stack.back();
                stack.pop_back();
                stack.push_back(lhs * rhs);
            } else if (token == "/") {
                int rhs = stack.back();
                stack.pop_back();
                int lhs = stack.back();
                stack.pop_back();
                stack.push_back(lhs / rhs);
            } else {
                stack.push_back(stoi(token));
            }
        }

        assert(stack.size() == 1);
        return stack.back();
    }
};

int main() {
    vector<string> ops1{"2", "1", "+", "3", "*"}, ops2{"4", "13", "5", "/", "+"},
            ops3{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    print_v(Solution().evalRPN(ops1));
    print_v(Solution().evalRPN(ops2));
    print_v(Solution().evalRPN(ops3));
}
