/**
 * 189. Rotate Array
 * https://leetcode.com/problems/rotate-array
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    void rotate_stride(vector<int> &nums, int k) {
        int length = nums.size(), rem = length % k, base = length - rem;
        print_var(length, rem, base);
        for (int i = 0; i < k && i < nums.size(); ++i) {
            // k is the stride, i is the offset
            print_varl(h1v(i), IndexedVector{nums});
            int j = nums.size() - k + i; // last pos
            int temp = nums[j];
            while (j - k >= 0) {
                print_varl(h3v(j), j, j - k, nums[j], nums[j - k]);
                nums[j] = nums[j - k];
                j -= k;
                print_var(IndexedVector{nums});
            }
            print_varl(aft, nums[i], temp);
            nums[i] = temp;
            print_var(IndexedVector{nums}, j);
        }
    }

    void rotate(vector<int> &nums, int k) {
        // bound the k
        k = k % nums.size();
        // rotate everything except the last K
        reverse(nums.begin(), nums.begin() + (nums.size() - k));
        // rotate the last K
        reverse(nums.begin() + (nums.size() - k), nums.end());
        // rotate everything
        reverse(nums.begin(), nums.end());
    }
};

int main() {
    vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    print_varl(h1("before"), IndexedVector{nums});
    Solution().rotate(nums, 3);
    print_varl(h1("after"), nums);
}
