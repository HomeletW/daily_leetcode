/**
 * 168. Excel Sheet Column Title
 * https://leetcode.com/problems/excel-sheet-column-title/
 */

#include "my_util.hpp"
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        int dividend = 'Z' - 'A' + 1;
        string result = "";
        do {
            -- columnNumber;   // each digit starts from 1, not 0, so sub 1
            int quotient = columnNumber / dividend;
            int remainder = columnNumber % dividend;
            result.push_back('A' + remainder);
            columnNumber = quotient;
        }
        while (columnNumber != 0);
        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{
    for (int i = 1; i < 1000; ++i)
    {
        cout << i << " : " << Solution().convertToTitle(i) << endl;
    }
}