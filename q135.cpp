/**
 * 135. Candy
 * https://leetcode.com/problems/candy
 *
 * Date: 2024-07-26
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        // This is an O(n) time and O(n) space solution
        // O(1) space solution is possible.
        vector<int> c_(ratings.size(), 1);

        // make sure left side is greater
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1] && c_[i] <= c_[i - 1]) {
                c_[i] = c_[i - 1] + 1;
            }
        }

        // make sure right size is greater
        for (int i = ratings.size() - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1] && c_[i] <= c_[i + 1]) {
                c_[i] = c_[i + 1] + 1;
            }
        }

        return accumulate(c_.begin(), c_.end(), 0);
    }
};

int main() {
    vector<int> ratings1{1, 0, 2}, ratings2{1, 2, 2};
    print_v(Solution().candy(ratings1));
    print_v(Solution().candy(ratings2));
}
