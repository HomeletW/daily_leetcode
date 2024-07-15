/**
 * 12. Integer to Roman
 * https://leetcode.com/problems/integer-to-roman
 */

#include "my_util.hpp"

using namespace std;

class Solution {

    void processDigit(string &res, char c_1, char c_5, char c_10, int digit) {
        switch (digit) {
            case 0:
                break;
            case 1:
                // I
                res.push_back(c_1);
                break;
            case 2:
                // II
                res.push_back(c_1);
                res.push_back(c_1);
                break;
            case 3:
                // III
                res.push_back(c_1);
                res.push_back(c_1);
                res.push_back(c_1);
                break;
            case 4:
                // IV
                // we are going to reverse it afterward
                res.push_back(c_5);
                res.push_back(c_1);
                break;
            case 5:
                // V
                res.push_back(c_5);
                break;
            case 6:
                // VI
                res.push_back(c_1);
                res.push_back(c_5);
                break;
            case 7:
                // VII
                res.push_back(c_1);
                res.push_back(c_1);
                res.push_back(c_5);
                break;
            case 8:
                // VIII
                res.push_back(c_1);
                res.push_back(c_1);
                res.push_back(c_1);
                res.push_back(c_5);
                break;
            case 9:
                // IX
                // we are going to reverse it afterward
                res.push_back(c_10);
                res.push_back(c_1);
                break;
            default:
                assert(false);
        }
    }

public:
    string intToRoman(int num) {
        if (num == 0) {
            return "";
        }
        // at most 3999
        int base = 1;
        string res;
        while (num != 0) {
            int digit = num % 10;
            switch (base) {
                case 1:
                    processDigit(res, 'I', 'V', 'X', digit);
                    break;
                case 10:
                    processDigit(res, 'X', 'L', 'C', digit);
                    break;
                case 100:
                    processDigit(res, 'C', 'D', 'M', digit);
                    break;
                case 1000:
                    processDigit(res, 'M', '-', '-', digit);
                    break;
                default:
                    assert(false);
            }
            num /= 10;
            base *= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    print_v(Solution().intToRoman(3749));
    print_v(Solution().intToRoman(58));
    print_v(Solution().intToRoman(1994));
    print_v(Solution().intToRoman(10));
}
