/**
 * 1. Two Sum
 * https://leetcode.com/problems/two-sum
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> map;  // complement -> index
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            print_var(sep, map, nums[i], target);
            if (map.contains(num)) {
                return {i, map[num]};
            } else {
                map[target - nums[i]] = i;
            }
        }
        return {};
    }
};

int main() {
    vector<int> nums{2, 7, 11, 15};
    print_line(Solution().twoSum(nums, 9));
}
