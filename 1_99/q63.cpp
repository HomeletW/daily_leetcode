/**
 * 63. Unique Paths II
 * https://leetcode.com/problems/unique-paths-ii
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles_old(vector<vector<int>> &obstacleGrid) {
//        set<pair<int, int>> visited;
        pair<int, int> start_p = pair<int, int>{0, 0};
        pair<int, int> end_p = pair<int, int>{obstacleGrid.size() - 1, obstacleGrid[0].size() - 1};
        deque<pair<int, int>> queue{};

        auto addIfCanVisit = [&](pair<int, int> p) {
            if (p.first <= end_p.first && p.second <= end_p.second &&
                obstacleGrid[p.first][p.second] != 1) {
                queue.push_back(p);
//                visited.insert(p);
            }
        };

        addIfCanVisit(start_p);
        int paths = 0;
        while (!queue.empty()) {
            print_v(queue);
            const auto &p = queue.front();
            if (p == end_p) {
                ++paths;
            } else {
                // push the available steps
                addIfCanVisit(make_pair(p.first + 1, p.second));
                addIfCanVisit(make_pair(p.first, p.second + 1));
            }
            queue.pop_front();
        }

        return paths;
    }

    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        // DP approach
        // mem[i][j] = paths to <i, j>
        vector<vector<int>> mem(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));

        for (int i = 0; i < obstacleGrid.size(); ++i) {
            for (int j = 0; j < obstacleGrid[0].size(); ++j) {
                if (obstacleGrid[i][j] == 1) {
                    continue;
                }

                if (j == 0 && i == 0) {
                    mem[i][j] = 1;
                } else if (j == 0) {
                    mem[i][j] = mem[i - 1][j];
                } else if (i == 0) {
                    mem[i][j] = mem[i][j - 1];
                } else {
                    mem[i][j] = mem[i][j - 1] + mem[i - 1][j];
                }
            }
        }

        return mem.back().back();
    }
};

int main() {
    vector<vector<int>> grid1{{0, 0, 0},
                              {0, 1, 0},
                              {0, 0, 0}};
    vector<vector<int>> grid2{{1, 0, 0},
                              {0, 0, 0},
                              {0, 0, 0}};
    print_v(Solution().uniquePathsWithObstacles(grid1));
    print_v(Solution().uniquePathsWithObstacles(grid2));
}
