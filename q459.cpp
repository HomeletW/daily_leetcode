/**
 * 459. Repeated Substring Pattern
 * https://leetcode.com/problems/repeated-substring-pattern/
 */
#include "my_util.hpp"
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // the main observation is that if s can be
        // constructed by repeating substring, then
        // s + s (s concat with s) must also contain s as substring
        //    abab => ab_abab_ab
        //    ababab => ab_ababab_abab
        // but there is one problem: any string would satisfy this
        // we can filter out non-repeating string by removing first and last letter
        //     ababc => ababcababc => babcabab
        string con = s + s;
        con.pop_back();
        auto pos = search(con.begin() + 1, con.end(), s.begin(), s.end());
        return pos != con.end();
    }
};

int main()
{
    cout << boolalpha << Solution().repeatedSubstringPattern("ababab") << endl;
    cout << boolalpha << Solution().repeatedSubstringPattern("ababc") << endl;
}