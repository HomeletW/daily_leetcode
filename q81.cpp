/**
 * 81. Search in Rotated Sorted Array II
 * https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                return true;
            }
            int leftV = nums[left], rightV = nums[right], midV = nums[mid];

            // since we could have duplicates, in the case that leftV == midV
            // the first half could be out of order OR could be all equals (in order).
            // If this happens, we can't deduce which side is in order, therefore
            // we will just switch to linear search.

            // Another observation is that in the case where leftV == midV and first half
            // is not in order (for example {5, 6, 7, 5, 5, 5, 5}), it is also necessary
            // that rightV == midV

            if (leftV == midV)
            {
                left++;
            }
            else if (leftV < midV)
            {
                // the first half is in order, pivot is in second half
                if (target >= leftV && target < midV)
                {
                    // the target is in first half
                    right = mid - 1;
                }
                else
                {
                    // target is in second half
                    left = mid + 1;
                }
            }
            else
            {
                // the second half is in order, pivot is in first half
                if (target <= rightV && target > midV)
                {
                    // the target is in second half
                    left = mid + 1;
                }
                else
                {
                    // target is in first half
                    right = mid - 1;
                }
            }
        }
        return false;
    }
};

int main()
{
    vector<int> nums = {2,5,6,0,0,1,2};
    cout << boolalpha << Solution().search(nums, 3);
}