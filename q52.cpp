/**
 * 52. N-Queens II
 * https://leetcode.com/problems/n-queens-ii
 *
 * Date: 2025-01-11
 */

#include "my_util.hpp"

using namespace std;

#define DEBUG_MODE 1

class Solution {
    vector<bool> _vertical_constraint;
    vector<bool> _diagonal_constraint;
    vector<bool> _anti_diagonal_constraint;
#if DEBUG_MODE == 1
    vector<pair<int, int>> _debug_placed_queue;
#endif
    int _n;
    int _num_placed;
    int _success;

    bool is_valid_move(int x, int y) {
        return !(_vertical_constraint[y]
                 || _diagonal_constraint[x - y + _n]
                 || _anti_diagonal_constraint[x + y]);
    }

    void add_queen(int x, int y) {
        _vertical_constraint[y] = true;
        _diagonal_constraint[x - y + _n] = true;
        _anti_diagonal_constraint[x + y] = true;
        ++_num_placed;
#if DEBUG_MODE == 1
        _debug_placed_queue.emplace_back(x, y);
#endif
    }

    void remove_queue(int x, int y) {
        _vertical_constraint[y] = false;
        _diagonal_constraint[x - y + _n] = false;
        _anti_diagonal_constraint[x + y] = false;
        --_num_placed;
#if DEBUG_MODE == 1
        auto iter = std::find_if(_debug_placed_queue.begin(), _debug_placed_queue.end(),
                                 [&](const auto &p) { return p.first == x && p.second == y; });
        assert(iter != _debug_placed_queue.end());
        _debug_placed_queue.erase(iter);
#endif
    }

#if DEBUG_MODE == 1

    void debug_print_board() {
        vector<vector<bool>> board(_n, vector<bool>(_n, false));
        for (const auto &p: _debug_placed_queue) {
            board[p.second][p.first] = true;
        }
        print_line(h2());
        for (const auto &line: board) {
            print_line(line);
        }
    }

#endif

public:
    int totalNQueens(int n) {
        _vertical_constraint.resize(n, false);
        _diagonal_constraint.resize(2 * n, false);
        _anti_diagonal_constraint.resize(2 * n, false);
        _n = n;
        _num_placed = 0;
        _success = 0;
        totalNQueens_helper(0);
        return _success;
    }

    void totalNQueens_helper(int x) {
        for (int y = 0; y < _n; ++y) {
            if (is_valid_move(x, y)) {
                add_queen(x, y);
                if (_num_placed == _n) {
                    ++_success;
                    #if DEBUG_MODE == 1
                    debug_print_board();
                    #endif
                } else {
                    totalNQueens_helper(x + 1);
                }
                remove_queue(x, y);
            }
        }
    }
};

int main() {
    print_v(Solution().totalNQueens(5));
}
