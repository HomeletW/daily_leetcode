/**
 * 228. Summary Ranges
 * https://leetcode.com/problems/summary-ranges
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        if (nums.empty()) {
            return {};
        }

        print_varl(sep, IndexedVector{nums});

        vector<string> res;
        int start = 0;
        for (int i = 1; i < nums.size(); ++i) {
            print_varl(h3(i), nums[i] - nums[start], i - start);
            if (nums[i] - nums[start] != i - start) {
                stringstream ss;
                if (start == i - 1) {
                    ss << nums[start];
                } else {
                    ss << nums[start] << "->" << nums[i - 1];
                }
                res.push_back(ss.str());
                start = i;
            }
        }

        print_v(start);

        stringstream ss;
        if (start == nums.size() - 1) {
            ss << nums[start];
        } else {
            ss << nums[start] << "->" << nums[nums.size() - 1];
        }
        res.push_back(ss.str());

        return res;
    }
};

int main() {
    vector<int> nums{0, 1, 2, 4, 5, 6};
    print_var(Solution().summaryRanges(nums));
}
