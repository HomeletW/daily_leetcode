/**
 * 169. Majority Element
 * https://leetcode.com/problems/majority-element
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        // Using Boyer-Moore Majority Vote Algorithm
        // https://www.cs.utexas.edu/~moore/best-ideas/mjrty/
        // The idea:
        // - walk over the list maintaining a candidate and a counter
        // - If the current element is invalid or not equal to the current candidate
        //      - decrement the counter
        //      - or set the candidate as the current
        // - Or, increment the counter (when it's the same)
        //
        // Why it works?
        // - The majority element is such element that has more than floor(n / 2)
        // - This means, the algorithm always yield the majority, because it must be at least one
        //   in the end. Of course, assuming a majority exists.
        int candidate_index = -1, counter = 0;
        for (int i = 0; i < nums.size(); ++i) {
            print_varl(h1v(i), IndexedVector{nums}, candidate_index, counter, nums[i]);
            if (candidate_index != -1) {
                print_var(nums[candidate_index]);
            }
            if (candidate_index == -1) {
                print_varl(h3("case 1"), "a");
                candidate_index = i;
                counter = 1;
            } else if (nums[i] == nums[candidate_index]) {
                print_varl(h3("case 2"), nums[i], nums[candidate_index]);
                ++counter;
            } else {
                print_varl(h3("case 3"), nums[i], nums[candidate_index]);
                --counter;
                if (counter <= 0) {
                    candidate_index = i;
                    counter = 1;
                }
            }
        }
        assert(candidate_index != -1);
        return nums[candidate_index];
    }
};

int main() {
//    vector<int> nums{2, 2, 1, 1, 1, 2, 2};
//    vector<int> nums{3, 2, 3};
    vector<int> nums{1, 3, 1, 1, 4, 1, 1, 5, 1, 1, 6, 2, 2};
    print_varl(bef, nums);
    auto res = Solution().majorityElement(nums);
    print_varl(aft, res, nums);
}
