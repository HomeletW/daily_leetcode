/**
 * 139. Word Break
 * https://leetcode.com/problems/word-break
 *
 * Date: 2025-01-14
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        // dp approach
        // i = index for s
        // j = index for wordDict
        // mem[i] = any(s[i-len:i] == wordDict[j] && mem[i - len(wordDict[j])] for j in range(len(wordDict)))
        vector<bool> mem(s.size() + 1, false);
        mem[0] = true;  // empty str can always be constructed
        for (int i = 1; i < s.size() + 1; ++i) {
            bool success = false;
            for (int j = 0; !success && j < wordDict.size(); ++j) {
                const string &word = wordDict[j];
                if (i >= word.size() && mem[i - word.size()]) {
                    const string_view substr{s.c_str() + i - word.size(), word.size()};
                    success = word == substr;
                    print_var_oneline(i, j, word, substr, success);
                }
            }
            mem[i] = success;
        }
        print_v(mem);
        return mem.back();
    }
};

int main() {
    vector<string> words1{"leet", "code"}, words2{"apple", "pen"}, words3{"cats", "dog", "sand", "and", "cat"};
    print_v(words1, Solution().wordBreak("leetcode", words1));
    print_v(words2, Solution().wordBreak("applepenapple", words2));
    print_v(words3, Solution().wordBreak("catsandog", words3));
}
