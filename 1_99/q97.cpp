/**
 * 97. Interleaving String
 * https://leetcode.com/problems/interleaving-string/
 */

#include "my_util.hpp"
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        this->s1 = &s1;
        this->s2 = &s2;
        this->s3 = &s3;
        if (s1.size() + s2.size() != s3.size())
        {
            return false;
        }

        dp = vector<vector<int>>(s1.size() + 1, vector<int>(s2.size() + 1, -1));

        return solve(0, 0);
    }
private:
    bool solve(int i, int j)
    {
        int k = i + j;
        if (k == s3->size())
        {
            return true;
        }

        if (dp[i][j] != -1)
        {
            return bool(dp[i][j]);
        }

        bool success = false;
        if (i < s1->size() && s3->at(k) == s1->at(i))
        {
            success = solve(i + 1, j);
        }
        if (j < s2->size() && s3->at(k) == s2->at(j))
        {
            success = success || solve(i, j + 1);
        }
        return dp[i][j] = success;
    }
    vector<vector<int>> dp;
    string* s1;
    string* s2;
    string* s3;
};

int main()
{
    cout << boolalpha << Solution().isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
    cout << boolalpha << Solution().isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
}