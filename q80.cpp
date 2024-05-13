/**
 * 80. Remove Duplicates from Sorted Array II
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (k < 2 || nums[i] != nums[k - 2]) {
                nums[k] = nums[i];
                ++k;
            }
        }
        return k;
    }

    int removeDuplicates2(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        } else if (nums.size() == 1) {
            return 1;
        }

        // i, j tracks the range of values
        // k is the write head
        int i, j, k;

        if (nums[0] == nums[1]) {
            i = 0;
            j = 2;
            k = 2;
        } else {
            i = 0;
            j = 1;
            k = 1;
        }

        // i points to the last value we checked,
        // j points to the current value
        // k points to the next value we should write to

        while (j < nums.size()) {
            print_varl(sep, i, j, k, nums);
            if (nums[i] == nums[j]) {
                ++j;
            } else {
                // first time discovering a different number
                if (j + 1 < nums.size() && nums[j] == nums[j + 1]) {
                    nums[k] = nums[j];
                    nums[k + 1] = nums[j + 1];
                    i = j;
                    ++j;
                    k += 2;
                } else {
                    nums[k] = nums[j];
                    i = j;
                    ++j;
                    ++k;
                }
            }
            print_varl(aft, i, j, k, nums);
        }

        return k;
    }
};

int main() {
//    vector<int> nums{1, 1, 1, 2, 2, 3};
    vector<int> nums{0, 0, 1, 1, 1, 1, 2, 3, 3};
//    vector<int> nums{1, 2, 2, 2};
    print_var(nums);
    int k = Solution().removeDuplicates(nums);
    print_var(k);
    nums.resize(k);
    print_var(nums);
}
