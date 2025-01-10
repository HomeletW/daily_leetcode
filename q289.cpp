/**
 * 289. Game of Life
 * https://leetcode.com/problems/game-of-life
 *
 * Date: 2025-01-10
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>> &board) {
        // use the second bit to record the new state,
        // then right-shift to apply the new state at the end
        vector<std::bitset<3>> mem(board[0].size(), 0);
        mem.assign(board[0].begin(), board[0].end());  // initialize as the first row
        print_v(mem);
        for (int i = 0; i < board.size(); ++i) {
            // construct mem to add the next row and remove the two row before this
            for (int j = 0; j < board[0].size(); ++j) {
                mem[j] <<= 1;
                if (i < board.size() - 1) {
                    mem[j].set(0, board[i + 1][j] & 1);
                }
            }
            print_v(mem);
            // iterate over mem to construct the new state
            int num_alive = mem[0].count();
            for (int j = 0; j < board[0].size(); ++j) {
                if (j < board[0].size() - 1) {
                    num_alive += mem[j + 1].count();
                }
                if (j >= 2) {
                    num_alive -= mem[j - 2].count();
                }
                print_var_oneline(i, j, num_alive);
                if (board[i][j]) {
                    if (num_alive - 1 == 2 || num_alive - 1 == 3) {
                        board[i][j] = 0b11;
                    } else {
                        board[i][j] = 0b01;
                    }
                } else {
                    if (num_alive == 3) {
                        board[i][j] = 0b10;
                    } else {
                        board[i][j] = 0b00;
                    }
                }
            }
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                board[i][j] >>= 1;
            }
        }
    }
};

int main() {
    vector<vector<int>> board1{{0, 1, 0},
                               {0, 0, 1},
                               {1, 1, 1},
                               {0, 0, 0}};
    print_v(board1);
    Solution().gameOfLife(board1);
    print_v(board1);
    vector<vector<int>> board2{{1, 1},
                               {1, 0}};
    print_vl(h1(), board2);
    Solution().gameOfLife(board2);
    print_v(board2);
    vector<vector<int>> board3{{0}};
    print_vl(h1(), board3);
    Solution().gameOfLife(board3);
    print_v(board3);
}
