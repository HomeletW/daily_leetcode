/**
 * 392. Is Subsequence
 * https://leetcode.com/problems/is-subsequence
 *
 * Date: 2024-09-03
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for (int j = 0; j < t.size(); ++j) {
            if (i == s.size()) {
                break;
            }
            if (s[i] == t[j]) {
                ++i;
            }
        }
        return i == s.size();
    }
};

int main() {
    print_v(Solution().isSubsequence("abc", "ahbgdc"));
    print_v(Solution().isSubsequence("axc", "ahbgdc"));
}
