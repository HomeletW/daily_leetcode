/**
 * 13. Roman to Integer
 * https://leetcode.com/problems/roman-to-integer
 */

#include "my_util.hpp"

using namespace std;

class Solution {
    // I             1
    // V             5
    // X             10
    // L             50
    // C             100
    // D             500
    // M             1000
    map<char, int> romanLetterToInt{{'I', 1},
                                    {'V', 5},
                                    {'X', 10},
                                    {'L', 50},
                                    {'C', 100},
                                    {'D', 500},
                                    {'M', 1000}};

public:
    int romanToInt(string s) {
        int val = 0;
        int i = 0;
        while (i < s.size()) {
            if (i + 1 < s.size() && romanLetterToInt[s[i]] < romanLetterToInt[s[i + 1]]) {
                val -= romanLetterToInt[s[i]];
            } else {
                val += romanLetterToInt[s[i]];
            }
            ++i;
        }
        return val;
    }
};

int main() {
    print_v(Solution().romanToInt("III")); // 3
    print_v(Solution().romanToInt("LVIII")); // 58
    print_v(Solution().romanToInt("MCMXCIV")); // 1994
}
