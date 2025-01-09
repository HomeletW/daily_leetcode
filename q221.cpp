/**
 * 221. Maximal Square
 * https://leetcode.com/problems/maximal-square
 *
 * Date: 2025-01-07
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        // look at the topLeft, left, and top element
        pair<int, int> offsets[]{{-1, -1},
                                 {-1, 0},
                                 {0,  -1}};
        int max_val = -1;
        vector<vector<int>> mem(matrix.size(), vector<int>(matrix[0].size(), 0));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == '0') {
                    mem[i][j] = 0;
                } else {
                    int min_val = -1;
                    for (const auto &off: offsets) {
                        int new_i = i + off.first;
                        int new_j = j + off.second;
                        if (new_i >= 0 && new_j >= 0) {
                            if (min_val == -1) {
                                min_val = mem[new_i][new_j];
                            } else {
                                min_val = std::min(min_val, mem[new_i][new_j]);
                            }
                        } else {
                            min_val = -1;
                            break;
                        }
                    }
                    if (min_val == -1) {
                        mem[i][j] = 1;
                    } else {
                        mem[i][j] = min_val + 1;
                    }
                }
                max_val = std::max(max_val, mem[i][j]);
            }
        }
        return max_val * max_val;
    }
};

int main() {

}
