/**
 * 153. Find Minimum in Rotated Sorted Array
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        // basically finding the pivot in the rotated array
        int pivot = binarySearchPivot(nums);
        if (pivot == -1) {
            return nums[0];
        } else {
            return nums[pivot];
        }
    }

    // copied from q33
    int binarySearchPivot(const vector<int> &nums) {
        int pivot = -1;
        int left = 0, right = nums.size();
        print_varl(h3("search pivot start"), left, right, IndexedVector{nums});
        while (left < right) {
            int mid = (left + right) / 2;
            print_varl(h3(), left, right, mid);
            assert(mid >= 1);
            if (nums[mid - 1] > nums[mid]) {
                return mid;
            } else if (nums[left] > nums[mid]) {
                // pivot is on the left side
                right = mid + 1;
            } else if (nums[right - 1] < nums[mid]) {
                // pivot is on the right side
                left = mid;
            } else {
                // not rotated
                break;
            }
            print_var(left, right);
        }
        return -1;
    }
};

int main() {
    vector<int> nums1{3, 4, 5, 1, 2}, nums2{4, 5, 6, 7, 0, 1, 2}, nums3{11, 13, 15, 17}, nums4{1};
    print_v(Solution().findMin(nums1));
    print_v(Solution().findMin(nums2));
    print_v(Solution().findMin(nums3));
    print_v(Solution().findMin(nums4));
}
