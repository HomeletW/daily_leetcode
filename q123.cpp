/**
 * 123. Best Time to Buy and Sell Stock III
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii
 *
 * Date: 2025-01-10
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // the state machine approach
        // S0  <----|      (initial state)
        //  |     /rest/
        //  |  -----|
        // /buy/
        //  |
        //  v
        // S1  <----|
        //  |     /rest/
        //  |  -----|
        // /sell/
        //  |
        //  v
        // S2  <----|
        //  |     /rest/
        //  |  -----|
        // /buy/
        //  |
        //  v
        // S3  <----|
        //  |     /rest/
        //  |  -----|
        // /sell/
        //  |
        //  v
        // Terminate  <----|
        //  |            /rest/
        //  |--------------|
        //
        // s0 is initialized as 0 money, the rest are uninitialized
        int s0 = 0, s1 = INT_MIN, s2 = INT_MIN, s3 = INT_MIN, t = INT_MIN;
        for (int p: prices) {
            s0 = s0;        // the only transition going into s0 is /rest/
            s1 = max(
                    s1,     // rest
                    s0 - p  // buy (transitioning from s1),
            );
            s2 = max(
                    s2,    // rest
                    s1 + p // sell (transitioning from s2),
            );
            s3 = max(
                    s3,    // rest
                    s2 - p // buy (transitioning from s3),
            );
            t = max(
                    t,     // rest
                    s3 + p // sell (transitioning from s4),
            );
            print_vl(h1(), s0, s1, s2, s3, t);
        }
        return max({s0, s1, s2, s3, t});
    }
};

int main() {
    vector<int> prices1{3, 3, 5, 0, 0, 3, 1, 4};
    vector<int> prices2{1, 2, 3, 4, 5};
    vector<int> prices3{7, 6, 4, 3, 1};
    print_v(Solution().maxProfit(prices1));
    print_v(Solution().maxProfit(prices2));
    print_v(Solution().maxProfit(prices3));
}
