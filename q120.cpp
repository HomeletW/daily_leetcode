/**
 * 120. Triangle
 * https://leetcode.com/problems/triangle
 *
 * Date: 2025-01-09
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        // since it's a triangle, the height is equals to the max level size
        vector<int> mem(triangle.size(), INT_MAX);
        mem.assign(triangle.back().begin(), triangle.back().end());
        int level = triangle.size() - 2;
        while (level >= 0) {
            for (int i = 0; i < triangle[level].size(); ++i) {
                int val = triangle[level][i];
                mem[i] = min(val + mem[i], val + mem[i + 1]);
            }
            --level;
        }
        return mem[0];
    }
};

int main() {
    vector<vector<int>> vec{{2},
                            {3, 4},
                            {6, 5, 7},
                            {4, 1, 8, 3}};
    vector<vector<int>> vec2{{-20}};
    print_v(Solution().minimumTotal(vec));
    print_v(Solution().minimumTotal(vec2));
}
