/**
 * 33. Search in Rotated Sorted Array
 * https://leetcode.com/problems/search-in-rotated-sorted-array
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        if (nums.empty()) {
            // nothing to search
            return -1;
        } else if (nums.size() == 1) {
            return nums.back() == target ? 0 : -1;
        } else if (nums.size() == 2) {
            return nums.back() == target ? 1 : (nums.front() == target ? 0 : -1);
        }

        // first search for the pivot
        int pivot = binarySearchPivot(nums);

        print_varl(h3("search pivot end"), pivot);

        // then use binary search on the subarray
        if (pivot == -1) {
            // not rotated
            assert(is_sorted(nums.begin(), nums.end()));
            auto iter = lower_bound(nums.begin(), nums.end(), target);
            if (iter != nums.end() && *iter == target) {
                return std::distance(nums.begin(), iter);
            } else {
                return -1;
            }
        } else if (target <= nums.back()) {
            print_line("searching in [pivot, size)");
            // search in [pivot, size)
            auto iter = lower_bound(nums.begin() + pivot, nums.end(), target);
            if (iter != nums.end() && *iter == target) {
                return std::distance(nums.begin(), iter);
            } else {
                return -1;
            }
        } else {
            print_line("searching in [0, pivot)");
            auto iter = lower_bound(nums.begin(), nums.begin() + pivot, target);
            if (iter != nums.begin() + pivot && *iter == target) {
                return std::distance(nums.begin(), iter);
            } else {
                return -1;
            }
        }
    }

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
//    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
//    vector<int> nums{4, 0, 2, 3};
//    vector<int> nums{1};
//    vector<int> nums{1, 3};
//    vector<int> nums{1, 3, 5};
    vector<int> nums{3, 5, 1};
//    print_line(Solution().search(nums, 1));
//    print_line(Solution().search(nums, 3));
//    print_line(Solution().search(nums, 0));
    print_line(Solution().search(nums, 1));
//    print_line(Solution().search(nums, 5));
}
