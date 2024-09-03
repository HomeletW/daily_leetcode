/**
 * 373. Find K Pairs with Smallest Sums
 * https://leetcode.com/problems/find-k-pairs-with-smallest-sums
 *
 * Date: 2024-08-29
 */

#include "my_util.hpp"
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
        if (k == 0 || nums1.empty() || nums2.empty()) {
            return {};
        }
        vector<vector<int>> pairs;

        auto cmp = [&](const pair<int, int> &i, const pair<int, int> &j) {
            return (nums1[i.first] + nums2[i.second]) > (nums1[j.first] + nums2[j.second]);
        };
        vector<pair<int, int>> min_heap{};
        for (int i = 0; i < nums2.size(); ++i) {
            min_heap.emplace_back(0, i);  // populate 0 mapped to all num2
        }

        while (pairs.size() < k) {
            assert(!min_heap.empty());
            std::pop_heap(min_heap.begin(), min_heap.end(), cmp);
            std::pair<int, int> p = min_heap.back();
            pairs.emplace_back(std::initializer_list<int>{nums1[p.first], nums2[p.second]});
            if (p.first + 1 < nums1.size()) {
                ++(min_heap.back().first);
                std::push_heap(min_heap.begin(), min_heap.end(), cmp);
            } else {
                min_heap.pop_back();
            }
        }

        return pairs;
    }
};

int main() {
    vector<int> nums1_1{1, 7, 11}, nums1_2{1, 1, 2}, nums1_3{1, 2, 4, 5, 6};
    vector<int> nums2_1{2, 4, 6}, nums2_2{1, 2, 3}, nums2_3{3, 5, 7, 9};
    print_v(Solution().kSmallestPairs(nums1_1, nums2_1, 3));
    print_v(Solution().kSmallestPairs(nums1_2, nums2_2, 2));
    print_v(Solution().kSmallestPairs(nums1_3, nums2_3, 3));
}
