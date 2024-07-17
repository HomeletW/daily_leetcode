/**
 * 238. Product of Array Except Self
 * https://leetcode.com/problems/product-of-array-except-self
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> result(nums.size(), 0);
        // Two pass
        int prod = 1;
        for (int i = 0; i < nums.size(); ++i) {
            result[i] = prod;
            prod *= nums[i];
        }
        prod = 1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            result[i] *= prod;
            prod *= nums[i];
        }
        return result;
    }
};

int main() {
    vector<int> nums1{1, 2, 3, 4}, nums2{-1, 1, 0, -3, 3};
    print_v(Solution().productExceptSelf(nums1));
    print_v(Solution().productExceptSelf(nums2));
}
