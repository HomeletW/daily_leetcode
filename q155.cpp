/**
 * 155. Min Stack
 * https://leetcode.com/problems/min-stack
 */

#include "my_util.hpp"

using namespace std;

class MinStack {
    // first is the actual values, second is the maintained minimum
    vector<pair<int, int>> stack;

public:
    MinStack() : stack{} {

    }

    void push(int val) {
        if (stack.empty()) {
            stack.emplace_back(val, val);
        } else {
            stack.emplace_back(val, min(stack.back().second, val));
        }
    }

    void pop() {
        stack.pop_back();
    }

    int top() {
        return stack.back().first;
    }

    int getMin() {
        return stack.back().second;
    }
};


int main() {
    MinStack minStack{};
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    print_v(minStack.getMin()); // return -3
    minStack.pop();
    print_v(minStack.top());    // return 0
    print_v(minStack.getMin()); // return -2
}
