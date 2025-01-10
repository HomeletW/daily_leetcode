/**
 * 64. Minimum Path Sum
 * https://leetcode.com/problems/minimum-path-sum
 *
 * Date: 2025-01-10
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        vector<vector<int>> mem(grid.size(), vector<int>(grid[0].size(), -1));
        // DP:
        // mem[i][j] = min(mem[i - 1][j], mem[i][j - 1]) + grid[i][j]
        // TODO: potential improvement
        //  can reduce DP size to min(2*width, 2*height), since only using last row/col in the grid
        mem[0][0] = grid[0][0];
        for (int j = 1; j < grid[0].size(); ++j) {
            mem[0][j] = mem[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < grid.size(); ++i) {
            mem[i][0] = mem[i - 1][0] + grid[i][0];
            for (int j = 1; j < grid[0].size(); ++j) {
                mem[i][j] = min(mem[i - 1][j], mem[i][j - 1]) + grid[i][j];
            }
        }
        return mem.back().back();
    }
};

int main() {
    vector<vector<int>> grid1{{1, 3, 1},
                              {1, 5, 1},
                              {4, 2, 1}};
    vector<vector<int>> grid2{{1, 2, 3},
                              {4, 5, 6}};
    print_v(Solution().minPathSum(grid1));
    print_v(Solution().minPathSum(grid2));
}
