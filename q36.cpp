/**
 * 36. Valid Sudoku
 * https://leetcode.com/problems/valid-sudoku
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        for (int i = 0; i < 9; ++i) {
            if (!verifyRow(board, i)) {
                return false;
            }
        }

        for (int j = 0; j < 9; ++j) {
            if (!verifyCol(board, j)) {
                return false;
            }
        }

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                if (!verifySquare(board, i, j)) {
                    return false;
                }
            }
        }

        return true;
    }

    bool verifyRow(vector<vector<char>> &board, int i) {
        unordered_set<char> set;
        for (int j = 0; j < 9; ++j) {
            char c = board[i][j];
            if (c == '.') {
                continue;
            } else if (isNotDigit(c)) {
                return false;
            }
            if (set.contains(c)) {
                return false;
            } else {
                set.insert(c);
            }
        }
        return true;
    }

    bool verifyCol(vector<vector<char>> &board, int j) {
        unordered_set<char> set;
        for (int i = 0; i < 9; ++i) {
            char c = board[i][j];
            if (c == '.') {
                continue;
            } else if (isNotDigit(c)) {
                return false;
            }
            if (set.contains(c)) {
                return false;
            } else {
                set.insert(c);
            }
        }
        return true;
    }

    bool verifySquare(vector<vector<char>> &board, int i, int j) {
        unordered_set<char> set;
        for (int i_add = 0; i_add < 3; ++i_add) {
            for (int j_add = 0; j_add < 3; ++j_add) {
                char c = board[i + i_add][j + j_add];
                if (c == '.') {
                    continue;
                } else if (isNotDigit(c)) {
                    return false;
                }
                if (set.contains(c)) {
                    return false;
                } else {
                    set.insert(c);
                }
            }
        }
        return true;
    }

    static bool isNotDigit(char c) {
        return c < '1' || c > '9';
    }
};

int main() {
//    vector<vector<char>> board{{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
//                               {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
//                               {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
//                               {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
//                               {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
//                               {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
//                               {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
//                               {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
//                               {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    vector<vector<char>> board{{'8', '3', '.', '.', '7', '.', '.', '.', '.'},
                               {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                               {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                               {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                               {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                               {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                               {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                               {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                               {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    print_var(board);
    print_line(Solution().isValidSudoku(board));
}
