/**
 * 121. Best Time to Buy and Sell Stock
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    // naive O(n) time, O(n) space
    int maxProfit_naive(vector<int> &prices) {
        vector<int> maxPrices(prices.size(), -1);  // index i record minimum prices from [i, end)
        int maxPrice = 0;
        for (int i = prices.size() - 1; i >= 0; --i) {
            maxPrice = max(maxPrice, prices[i]);
            maxPrices[i] = maxPrice;
        }

        print_var(prices, maxPrices);

        int maxProfit = 0;
        for (int i = 0; i < prices.size(); ++i) {
            maxProfit = max(maxProfit, maxPrices[i] - prices[i]);
        }
        return maxProfit;
    }

    // O(n) time, O(1) space
    int maxProfit_constantSpace(vector<int> &prices) {
        // use two pointer
        // left points to the minimum of [0, right)
        int maxProfit = 0;
        int left = 0, right = 0;
        print_varl(h1("start"), IndexedVector{prices}, left, right);
        while (right < prices.size()) {
            if (prices[right] < prices[left]) {
                left = right;
            } else {
                maxProfit = max(maxProfit, prices[right] - prices[left]);
            }
            ++right;
            print_varl(sep, left, right, maxProfit);
        }
        return maxProfit;
    }

    // Kadane's algorithm, O(n) time, O(1) space
    // in case interviewers twist things up and give you
    // the differences of prices
    //
    // Say the answer is to buy at day2 and sell at day6
    // when you keep adding the differences:
    //      (d2 - d3) + (d3 - d4) + (d4 - d5) + (d5 - d6)
    //   =  d2 - d6 (all other terms cancels out)
    // When the profit falls below zero, essentially, we found
    // a day that is higher in prices than what we bought,
    // so it's better off start fresh on that day.
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) {
            return 0;
        }

        int profit = 0;
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            profit += prices[i] - prices[i - 1];
            if (profit <= 0) {
                profit = 0;
            }
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }
};

int main() {
    std::vector<int> prices{7, 1, 5, 3, 6, 4};
    print_line(Solution().maxProfit_naive(prices));
    print_line(Solution().maxProfit_constantSpace(prices));
    print_line(Solution().maxProfit(prices));
}
