/**
 * 403. Frog Jump
 * https://leetcode.com/problems/frog-jump/
 */

#include "my_util.hpp"
using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        // dp approach
        // l is the current stone length, k is the current step length
        // dp[l][k] = l is a stone && (dp[l+k][k] || dp[l+(k-1)][k-1] || dp[l+(k+1)][k+1])

        maxLength = stones.back();
        stonesHash = set<int>(stones.begin(), stones.end());  // for quick look up if a place has a stone
        dp = vector<vector<int>>(maxLength + 1, vector<int>(maxLength + 1, -1));

        return solve(0, 1);
    }
private:
    bool solve(int l, int k)
    {
        if (l < 0 || l > maxLength || k <= 0 || k > maxLength)
        {
            return false;
        }
        if (dp[l][k] != -1)
        {
            return dp[l][k];
        }
        if (!stonesHash.contains(l))
        {
            return dp[l][k] = false;
        }
        return dp[l][k] = solve(l + k, k) || solve(l + (k - 1), k - 1) || solve(l + (k + 1), k + 1);
    }

    int maxLength;
    set<int> stonesHash;
    vector<vector<int>> dp;
};

int main()
{
    vector<int> stones{0, 1, 3, 5, 6, 8, 12, 17};
    cout << boolalpha << Solution().canCross(stones) << endl;
}