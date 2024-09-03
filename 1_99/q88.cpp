/**
 * 88. Merge Sorted Array
 * https://leetcode.com/problems/merge-sorted-array/description
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        // idea: merge from behind
        // - i tracks index in nums1
        // - j tracks index in nums2
        // - k tracks the current write head
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0) {
            assert(k >= i);
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i];
                --i;
            } else if (nums1[i] < nums2[j]) {
                nums1[k--] = nums2[j];
                --j;
            } else {
                nums1[k--] = nums1[i];
                nums1[k--] = nums2[j];
                --j;
                --i;
            }
        }

        // append the rest
        while (i >= 0) {
            nums1[k] = nums1[i];
            --i;
            --k;
        }
        while (j >= 0) {
            nums1[k] = nums2[j];
            --j;
            --k;
        }

        assert(k < 0);
    }
};

int main() {
//    vector<int> a{1, 3, 5, 6, 8, 9}, b{2, 4, 7, 10};
    vector<int> a{1, 2, 3, -1, -1, -1}, b{2, 5, 6};
    print_var(a, b);
    Solution().merge(a, 3, b, 3);
    print_var(a, b);
}