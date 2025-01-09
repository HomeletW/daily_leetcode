/**
 * 11. Container With Most Water
 * https://leetcode.com/problems/container-with-most-water
 *
 * Date: 2025-01-07
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int max_area = 0;
        // the initial position maximize the x-axis
        int left = 0, right = height.size() - 1;
        while (left < right) {
            int x_axis = right - left;
            int y_axis = std::min(height[left], height[right]);
            int curr_area = x_axis * y_axis;
            if (curr_area > max_area) {
                max_area = curr_area;
            }
            // try to update left/right to maximize the y-axis
            if (height[left] > height[right]) {
                // the right is the bottleneck
                // find the next right value that can make progress
                // e.g. larger than the current right value
                int right_val = height[right];
                do
                    --right;
                while (left < right && height[right] <= right_val);
            } else {
                // the left is the bottleneck
                int left_val = height[left];
                do
                    ++left;
                while (left < right && height[left] <= left_val);
            }
        }
        return max_area;
    }
};

int main() {
    std::vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
    print_v(Solution().maxArea(height));
}
