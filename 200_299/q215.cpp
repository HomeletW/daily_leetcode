/**
 * 215. Kth Largest Element in an Array
 * https://leetcode.com/problems/kth-largest-element-in-an-array
 *
 * Date: 2024-07-26
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        assert(nums.size() >= k);

        // heap approach
        vector<int> max_heap(nums.begin(), nums.end());
        make_heap(max_heap.begin(), max_heap.end(), std::less<int>{});

        auto beg = max_heap.begin();
        auto end = max_heap.end();
        for (int i = 0; i < k - 1; ++i) {
            print_v(max_heap);
            pop_heap(beg, end, std::less<int>{});
            --end;
        }
        print_v(max_heap);

        return *beg;
    }
};

int main() {
    vector<int> nums1{3, 2, 1, 5, 6, 4}, nums2{3, 2, 3, 1, 2, 4, 5, 5, 6};
    print_v(Solution().findKthLargest(nums1, 2));
    print_v(Solution().findKthLargest(nums2, 4));
}
