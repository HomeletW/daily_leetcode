/**
 * 15. 3Sum
 * https://leetcode.com/problems/3sum/description
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:

    vector<vector<int>> threeSum(vector<int> &nums) {
        // idea:
        // - identify that threeSum is iteration + twoSum
        // - the problem is to identify the duplicates
        //      - one idea is to use hash set
        //      - here we simply skip over the duplicated values to avoid this case
        if (nums.size() < 3) {
            return {};
        }
        vector<vector<int>> result;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2;) {
            twoSum(nums, result, i);
            do {
                ++i;
            } while (i < nums.size() && nums[i - 1] == nums[i]);
        }
        return result;
    }

    void twoSum(vector<int> &nums, vector<vector<int>> &result, int i) {
        int j = i + 1, k = nums.size() - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            print_var(sep, nums, i, j, k, sum, result);
            if (sum < 0) {
                ++j;
            } else if (sum > 0) {
                --k;
            } else {
                result.emplace_back(vector<int>{nums[i], nums[j], nums[k]});
                do {
                    ++j;
                } while (j < nums.size() && nums[j - 1] == nums[j]);
                do {
                    --k;
                } while (k >= 0 && nums[k + 1] == nums[k]);
            }
        }
    }
};

int main() {
    vector<int> num{-1, 0, 1, 2, -1, -4};
    print_var(num);
    print_line(Solution().threeSum(num));
}