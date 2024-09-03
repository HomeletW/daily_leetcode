/**
 * 6. Zigzag Conversion
 * https://leetcode.com/problems/zigzag-conversion
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        int zigZagSize = numRows * 2 - 2;
        int numZigZag = (s.size() + zigZagSize - 1) / zigZagSize;  // ceil
        string res;
        res.reserve(s.size());

        // special handles the first row
        for (int i = 0; i < numZigZag; ++i) {
            assert(i * zigZagSize < s.size());
            res.push_back(s[i * zigZagSize]);
        }

        vector<char> s_str(s.begin(), s.end());
        print_vl(sep, zigZagSize, numZigZag, IndexedVector{s_str});

        print("res: \"", res, "\"\n");

        // handles the centerpieces
        for (int row = 1; row < numRows - 1; ++row) {
            for (int i = 0; i < numZigZag; ++i) {
                int idx1 = i * zigZagSize + row;
                int idx2 = (i + 1) * zigZagSize - row;
                print_varl(h3v(row, i), idx1, idx2);
                if (idx1 < s.size())
                    res.push_back(s[idx1]);
                if (idx2 < s.size())
                    res.push_back(s[idx2]);
            }
        }

        print("res: \"", res, "\"\n");

        // special handles the last row
        for (int i = 0; i < numZigZag; ++i) {
            int idx = i * zigZagSize + numRows - 1;
            print_varl(h3v(i), idx);
            if (idx < s.size())
                res.push_back(s[idx]);
        }

        print("res: \"", res, "\"\n");

        return res;
    }
};

int main() {
    print_var(Solution().convert("PAYPALISHIRING", 1));
    print_var(Solution().convert("PAYPALISHIRING", 2));
    print_var(Solution().convert("PAYPALISHIRING", 3));
    print_var(Solution().convert("PAYPALISHIRING", 4));
}
