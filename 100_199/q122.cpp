/**
 * 122. Best Time to Buy and Sell Stock II
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) {
            return 0;
        }

        // - hold means      holding current stock (not sell), or buy
        // - nothold means   selling current holding, or remain not hold

        // DP approach: mem[i] = current principle archived at i of the corresponding state
        vector<array<int, 2>> mem(prices.size(), array<int, 2>{0, 0});

        mem[0][0] = -prices[0];
        mem[0][1] = 0;
        for (int i = 1; i < prices.size(); ++i) {
            int prevHold = mem[i - 1][0], prevNotHold = mem[i - 1][1];
            int currHold, currNotHold;

            // must ends up holding stocks
            currHold = max(
                    prevHold,                 // keeps holding
                    prevNotHold - prices[i]   // buy
            );

            // must ends up not holding stocks
            currNotHold = max(
                    prevHold + prices[i],   // sell out holdings
                    prevNotHold             // keeps not hold
            );

            mem[i][0] = currHold;
            mem[i][1] = currNotHold;
        }

        print_var(mem);
        return max(mem.back()[0], mem.back()[1]);
    }
};

int main() {
//    vector<int> prices{7, 1, 5, 3, 6, 4};
    vector<int> prices{3, 2, 5, 8};
    print_var(Solution().maxProfit(prices));
}
