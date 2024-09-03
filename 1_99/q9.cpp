/**
 * 9. Palindrome Number
 * https://leetcode.com/problems/palindrome-number
 */

#include "my_util.hpp"
#include "math.h"

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        // calculate the number of digit
        int num_digit = 0;
        while (x >= pow(10, num_digit)) ++num_digit;

        print_varl(sep, x, num_digit);

        if (num_digit == 1) {
            return true;
        }

        // reverse half of the x
        int count = 0;
        int reversed_x = 0;
        int digit;
        while (count < num_digit / 2) {
            digit = x % 10;
            reversed_x += digit * pow(10, num_digit / 2 - count - 1);
            x = x / 10;
            ++count;
            print_varl(h3(x * pow(10, count)), digit, reversed_x);
        }

        // handles the center digit
        if (num_digit % 2 == 1) {
            x = x / 10;
        }

        print_vl(h3("end"), reversed_x, x);

        return x == reversed_x;
    }
};

int main() {
    print_line(Solution().isPalindrome(121));
    print_line(Solution().isPalindrome(10));
    print_line(Solution().isPalindrome(1212));
    print_line(Solution().isPalindrome(123321));
}
