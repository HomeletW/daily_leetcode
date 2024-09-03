/**
 *  518. Coin Change II
 *  https://leetcode.com/problems/coin-change-ii/description/
 */

#include "my_util.hpp"

using namespace std;

/**
 * Use a DP approach:
 * - numOfWays(curr coinIndex to consider, amount) returns the number of ways
 *   to construct amount considering coins[index]
 * - DP structure:
 *      - if i cannot be considered (i.e. coins[i] > amount) then
 *          numOfWays[i][amount] = numOfWays[i+1][amount]
 *      - if i can be considered then
 *          numOfWays[i][amount] = numOfWays[i+1][amount] + numOfWays[i][amount - coins[i]]
 */

class Solution {
    vector<int> coins;
    vector<vector<int>> tbl;
public:
    // calculate tbl[index][amount]
    int numberOfWays(int index, int amount)
    {
        if (amount == 0)
        {
            // no need to use any coins
            return 1;
        }
        else if (index == coins.size())
        {
            // base case
            return 0;
        }
        else if (tbl[index][amount] != -1)
        {
            // if already calculated, return that
            return tbl[index][amount];
        }

        // main logic
        if (coins[index] > amount)
        {
            return tbl[index][amount] = numberOfWays(index + 1, amount);
        }
        else {
            return tbl[index][amount] = numberOfWays(index + 1, amount) + numberOfWays(index, amount - coins[index]);
        }
    }

    int change(int amount, vector<int>& coins) {
        this->coins = coins;
        tbl = vector<vector<int>>{coins.size(), vector<int>(amount + 1, -1)};
        auto v2 = vector<int>{amount + 1, -1};
        int i = numberOfWays(0, amount);
        return i;
    }
};

int main()
{
    vector<int> coins{1,2,5};
    cout << Solution().change(5, coins);
}