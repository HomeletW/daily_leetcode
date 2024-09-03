/**
 * 42. Trapping Rain Water
 * https://leetcode.com/problems/trapping-rain-water/description
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    int trap(vector<int> &height) {
        // idea1: two pointer
        //      - left min and right min tracks the max from both side.
        //      - the water can fill up to the minimum of the two max
        int left = 0, right = height.size() - 1;
        int left_max = height[left], right_max = height[right];
        int rain = 0;
        while (left < right) {
            print_line(sep);
            if (left_max < right_max) {
                print_var("before", left, left_max, height[left], rain);
                ++left;
                left_max = max(left_max, height[left]);
                rain += left_max - height[left];
                print_var("after", left, left_max, height[left], rain);
            } else {
                print_var("before", right, right_max, height[right], rain);
                --right;
                right_max = max(right_max, height[right]);
                rain += right_max - height[right];
                print_var("after", right, right_max, height[right], rain);
            }
        }
        return rain;
    }
};

int main() {
//    vector<int> height{3, 2, 1, 2, 3};
    vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    print_var(height);
    print_line(Solution().trap(height));
}
