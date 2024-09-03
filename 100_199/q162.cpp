/**
 * 162. Find Peak Element
 * https://leetcode.com/problems/find-peak-element
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        // Binary search approach:
        // - each time check the three element: mid - 1, mid, mid + 1
        // - if found a peak, return it
        // - else if, mid < mid - 1 (a downwards slop \), go to left side
        // - else if, mid < mid + 1 (a upwards slop /), go to right side
        // this works because the nums[i] != nums[i + 1]
        // and that nums[-1] = -inf, and nums[size] = -inf

        print_varl(sep, IndexedVector{nums});

        if (nums.empty()) {
            return -1;
        } else if (nums.size() == 1) {
            return 0;
        }

        // to ensure valid indexes, check for the side separately
        if (nums[0] > nums[1]) {
            return 0;
        } else if (nums[nums.size() - 1] > nums[nums.size() - 2]) {
            return nums.size() - 1;
        }

        int left = 1, right = nums.size() - 1;
        while (left < right) {
            int mid = (right + left) / 2;
            print_vl(h3v(left, right), mid, nums[mid - 1], nums[mid], nums[mid + 1]);
            assert(mid >= 0 && mid <= nums.size() - 1);
            assert(mid + 1 >= 0 && mid + 1 <= nums.size() - 1);
            assert(mid - 1 >= 0 && mid - 1 <= nums.size() - 1);
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            } else if (nums[mid] < nums[mid - 1]) {
                right = mid;
            } else {
                return mid;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> nums1{1, 2, 3, 1}, nums2{1, 2, 1, 3, 5, 6, 4}, nums3{1, 3, 2, 1};
    print_var(Solution().findPeakElement(nums1));
    print_var(Solution().findPeakElement(nums2));
    print_var(Solution().findPeakElement(nums3));
}
