/**
 * 55. Jump Game
 * https://leetcode.com/problems/jump-game
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums) {
        // dp apparoch
        vector<bool> mem(nums.size(), false);
        print_var(mem, nums);
        int length = nums.size();
        for (int i = nums.size() - 1; i >= 0; --i) {
            print_line(sep);
            if (nums[i] >= length - i - 1) {
                print_varl("first", nums[i]);
                mem[i] = true;
            } else {
                bool res = false;
                print_varl("second", nums[i]);
                for (int j = 1; j <= nums[i] && i + j < nums.size(); ++j) {
                    print_varl(j, mem[i + j]);
                    // implements short circit OR logic
                    if (mem[i + j]) {
                        res = true;
                        break;
                    }
                }
                mem[i] = res;
            }
        }
        print_var(mem);
        return mem[0];
    }

//    bool canJump(vector<int> &nums) {
//        // keep track of the max position that can be reached
//        int last_reach = 0;
//        int length = nums.size();
//        for (int i = 0; i < nums.size(); ++i) {
//            last_reach = max(last_reach, i + nums[i]);
//        }
//    }
};

int main() {
//    vector<int> nums{2, 3, 1, 1, 4};
//    vector<int> nums{3, 2, 1, 0, 4};
    vector<int> nums{1, 2, 3};
    print_line(Solution().canJump(nums));
}
