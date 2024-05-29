/**
 * 67. Add Binary
 * https://leetcode.com/problems/add-binary
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        res.reserve(max(a.size(), b.size()) + 1);

        char carry = '0';
        int ai = a.size() - 1, bi = b.size() - 1;

        print_var(a.size(), b.size());
        while (ai >= 0 && bi >= 0) {
            print_varl(h3(), ai, bi);
            res.push_back(binary_add(a[ai], b[bi], carry));
            --ai;
            --bi;
        }

        while (ai >= 0) {
            res.push_back(binary_add(a[ai], '0', carry));
            --ai;
        }

        while (bi >= 0) {
            res.push_back(binary_add(b[bi], '0', carry));
            --bi;
        }

        if (carry != '0') {
            res.push_back(carry);
        }

        reverse(res.begin(), res.end());

        print_var(a, b, res);

        return res;
    }

    char binary_add(char c1, char c2, char &carry) {
        if (carry == '0') {
            if (c1 == '0') {
                if (c2 == '0') {
                    carry = '0';
                    return '0';
                } else {
                    carry = '0';
                    return '1';
                }
            } else {
                if (c2 == '0') {
                    carry = '0';
                    return '1';
                } else {
                    carry = '1';
                    return '0';
                }
            }
        } else {
            if (c1 == '0') {
                if (c2 == '0') {
                    carry = '0';
                    return '1';
                } else {
                    carry = '1';
                    return '0';
                }
            } else {
                if (c2 == '0') {
                    carry = '1';
                    return '0';
                } else {
                    carry = '1';
                    return '1';
                }
            }
        }
    }
};

int main() {
    print(sep);
    print_var(Solution().addBinary("11", "1"));
    print(sep);
    print_var(Solution().addBinary("1010", "1011"));
}
