/**
 * 918. Maximum Sum Circular Subarray
 * https://leetcode.com/problems/maximum-sum-circular-subarray
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int> &nums) {
        // similar to q121, using Kadane's algorithm
        // but since the array is circular, we have to consider the case
        // that the max sum across the boundary
        // - case 1: regular case
        // - case 2: theory: maxSum contains crossing the boundary = totalSum - minSum
        print_vl(sep, IndexedVector{nums});
        int maxSum = maxSubarraySum(nums);
        int minSum = minSubarraySum(nums);
        int totalSum = std::accumulate(nums.begin(), nums.end(), 0);
        print_v(maxSum, minSum, totalSum);
        if (minSum == totalSum) {
            // this case covers when the whole array is all negatives
            // so the minSum is the sum of all values.
            // In that case, the maxSum would be an empty array
            // but this is not an accepted case.
            return maxSum;
        } else {
            return max(maxSum, totalSum - minSum);
        }
    }

    int maxSubarraySum(const vector<int> &nums) {
        // the regular Kadane algorithm
        int sum = 0, maxSum = numeric_limits<int>::min();
        for (int num: nums) {
            int newSum = sum + num;
            if (newSum < num) {  // better off to start fresh
                sum = num;
            } else {
                sum = newSum;
            }
            maxSum = max(maxSum, sum);
        }

        return maxSum;
    }

    int minSubarraySum(const vector<int> &nums) {
        // the regular Kadane algorithm
        int sum = 0, minSum = numeric_limits<int>::max();
        for (int num: nums) {
            int newSum = sum + num;
            if (newSum > num) {  // better off to start fresh
                sum = num;
            } else {
                sum = newSum;
            }
            minSum = min(minSum, sum);
        }

        return minSum;
    }
};

int main() {
    vector<int> nums1{1, -2, 3, -2}, nums2{5, -3, 5}, nums3{-3, -2, -3}, nums4{6, 9, -3}, nums5{2, -2, 2, 7, 8, 0};
    print_v(Solution().maxSubarraySumCircular(nums1));
    print_v(Solution().maxSubarraySumCircular(nums2));
    print_v(Solution().maxSubarraySumCircular(nums3));
    print_v(Solution().maxSubarraySumCircular(nums4));
    print_v(Solution().maxSubarraySumCircular(nums5));
}
