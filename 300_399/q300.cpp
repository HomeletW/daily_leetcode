/**
 * 300. Longest Increasing Subsequence
 * https://leetcode.com/problems/longest-increasing-subsequence
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        // DP approach, mem[i] records the LIS that ends with nums[i]
        vector<int> mem(nums.size(), 0);

        for (int i = 0; i < nums.size(); ++i) {
            // find the largest element that is before i
            int largest = -1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    if (largest == -1 || mem[j] > mem[largest]) {
                        largest = j;
                    }
                }
            }

            if (largest == -1) {
                mem[i] = 1;
            } else {
                mem[i] = mem[largest] + 1;
            }
        }
        print_v(nums, mem);

        auto iter = std::max_element(mem.begin(), mem.end());
        return *iter;
    }
};

int main() {
    vector<int> nums1{10, 9, 2, 5, 3, 7, 101, 18};
    print_v(Solution().lengthOfLIS(nums1));
}
