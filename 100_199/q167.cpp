/**
 * 167. Two Sum II - Input Array Is Sorted
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                break;
            } else if (sum < target) {
                ++left;
            } else {
                --right;
            }
        }
        return {left + 1, right + 1};
    }
};

int main() {
    vector<int> nums1{2, 7, 11, 15}, nums2{2, 3, 4}, nums3{-1, 0};
    print_v(Solution().twoSum(nums1, 9));
    print_v(Solution().twoSum(nums2, 6));
    print_v(Solution().twoSum(nums3, -1));
}
