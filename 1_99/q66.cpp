/**
 * 66. Plus One
 * https://leetcode.com/problems/plus-one
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> result;
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            int val = digits[i] + carry;
            carry = val / 10;
            val = val % 10;
            print_vo(val, carry);
            result.push_back(val);
        }
        if (carry != 0) {
            result.push_back(carry);
        }
        reverse(result.begin(), result.end());
        return result;
    }

    vector<int> plusOne_alt(vector<int> &digits) {
        int base = 1;
        int val = 0;
        for (int i = digits.size() - 1; i >= 0; --i) {
            val += digits[i] * base;
            base *= 10;
        }
        print_v(digits);
        print_v(val);
        val += 1;
        print_v(val);
        vector<int> result;
        while (val != 0) {
            result.push_back(val % 10);
            val /= 10;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    vector<int> d1{1, 2, 3}, d2{4, 3, 2, 1}, d3{9, 9, 9};
    print_v(Solution().plusOne(d1));
    print_v(Solution().plusOne(d2));
    print_v(Solution().plusOne(d3));
}
