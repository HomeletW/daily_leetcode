/**
 * 646. Maximum Length of Pair Chain
 * https://leetcode.com/problems/maximum-length-of-pair-chain/
 */

#include "my_util.hpp"
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // dp approach
        // sort by first pair
        // dp[i] = the longest chain can be formed if started with pairs[i]
        // sub structure here is
        //      dp[i] = max(dp[j] + 1)   for each j if pairs[i][1] < pairs[j][0]
        // n^2 time complexity

        // greedy approach
        // sort by second pair
        // for each pair in sorted j, maintain the current longest chain end i,
        // if pairs[i][1] < pair[j][0], update the longest chain end to j

        sort(pairs.begin(), pairs.end(), [](const auto& p1, const auto& p2){
            return p1[1] < p2[1];
        });

        int i = 0;
        int longest = 1;
        for (int j = 1; j < pairs.size(); ++j)
        {
            if (pairs[i][1] < pairs[j][0])
            {
                i = j;
                ++longest;
            }
        }

        return longest;
    }
};

int main()
{
//    vector<vector<int>> pairs{{1, 2}, {2, 3}, {3, 4}};
    vector<vector<int>> pairs{{1, 2}, {7, 8}, {4, 5}};
    cout << Solution().findLongestChain(pairs);
}