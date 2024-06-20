/**
 * 45. Jump Game II
 * https://leetcode.com/problems/jump-game-ii
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        if (nums.size() == 1) {
            return 0;
        }
        print_line(sep);
        // since we can jump as much as we want,
        // the goal is to go as far as possible
        int farthestReachThisRound = 0, jumps = 0, currentReach = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int reach = i + nums[i];
            farthestReachThisRound = max(farthestReachThisRound, reach);
            print_vl(h3v(i), reach, farthestReachThisRound, currentReach, jumps);

            // reached end
            if (farthestReachThisRound >= nums.size() - 1) {
                ++jumps;
                break;
            }

            // end of round
            if (i == currentReach) {
                ++jumps;
                currentReach = farthestReachThisRound;
                farthestReachThisRound = i;
            }
        }

        return jumps;
    }
};

int main() {
    vector<int> nums1{2, 3, 1, 1, 4}, nums2{2, 3, 0, 1, 4}, nums3{1, 3, 2}, nums4{1, 2}, nums5{1, 1, 1, 1};
    print_v(Solution().jump(nums1));
    print_v(Solution().jump(nums2));
    print_v(Solution().jump(nums3));
    print_v(Solution().jump(nums4));
    print_v(Solution().jump(nums5));
}
