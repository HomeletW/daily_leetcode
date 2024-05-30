/**
 * 17. Letter Combinations of a Phone Number
 * https://leetcode.com/problems/letter-combinations-of-a-phone-number
 */

#include "my_util.hpp"

using namespace std;

class Solution {
    map<char, string_view> digitMap;
public:
    Solution() : digitMap{{'1', ""},
                          {'2', "abc"},
                          {'3', "def"},
                          {'4', "ghi"},
                          {'5', "jkl"},
                          {'6', "mno"},
                          {'7', "pqrs"},
                          {'8', "tuv"},
                          {'9', "wxyz"}} {}

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        int totalNum = 1;
        for (int i = 0; i < digits.size(); ++i) {
            totalNum *= digitMap[digits[i]].size();
        }

        vector<string> res(totalNum, string(digits.size(), ' '));

        print_vl(sep, totalNum, res);

        int stride = 1;
        for (int i = 0; i < digits.size(); ++i) {
            auto bank = digitMap[digits[i]];
            totalNum /= bank.size();

            int index = 0;
            for (int k = 0; k < stride; ++k) {
                for (int l = 0; l < bank.size(); ++l) {
                    for (int j = 0; j < totalNum; ++j) {
                        res[index][i] = bank[l];
                        ++index;
                    }
                }
            }

            print_vl(h2v(i), bank, totalNum, stride, res);

            stride *= bank.size();
        }

        return res;
    }
};

int main() {
    print_var(Solution().letterCombinations("23"));
    print_var(Solution().letterCombinations("234"));
}
