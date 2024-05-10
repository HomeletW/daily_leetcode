/**
 * 14. Longest Common Prefix
 * https://leetcode.com/problems/longest-common-prefix/description
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) {
            return "";
        }
        int prefix = strs[0].size();
        for (int i = 1; i < strs.size(); ++i) {
            if (prefix == 0) {
                break;
            }
            int j;
            for (j = 0; j < strs[i].size() && j < prefix; ++j) {
                if (strs[i][j] != strs[0][j]) {
                    break;
                }
            }
            prefix = min(prefix, j);
        }
        return strs[0].substr(0, prefix);
    }
};

int main() {
//    vector<string> strs{"flower", "flow", "flight"};
    vector<string> strs{"dog", "racecar", "car"};
    print_var(strs);
    print(Solution().longestCommonPrefix(strs));
}