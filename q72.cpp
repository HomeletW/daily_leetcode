/**
 * 72. Edit Distance
 * https://leetcode.com/problems/edit-distance
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        // DP approach
        // mem[i][j] = minimum step to transform word1[0...i] to word2[0...j]
        // assume board is word1.size() x word2.size()
        // - insert corresponds to moving down in the board (0, +1),
        //   because you would now match word1 to word2[1:]
        // - delete corresponds to moving side in the board (+1, 0),
        //   because you would now match word1[1:] to word2
        // - replace would be move to the sideways (+1, +1)
        //   because you would now match word1[1:] to word2[1:]

        vector<vector<int>> mem(word1.size() + 1, vector<int>(word2.size() + 1, -1));

        // initialize
        for (int i = 0; i < word1.size() + 1; ++i) {
            mem[i][0] = i;
        }
        for (int j = 0; j < word2.size() + 1; ++j) {
            mem[0][j] = j;
        }

        for (int i = 1; i < word1.size() + 1; ++i) {
            for (int j = 1; j < word2.size() + 1; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    mem[i][j] = mem[i - 1][j - 1];
                } else {
                    int insert_cost = mem[i - 1][j];
                    int delete_cost = mem[i][j - 1];
                    int replace_cost = mem[i - 1][j - 1];
                    mem[i][j] = min(min(insert_cost, delete_cost), replace_cost) + 1;
                }
            }
        }

        print_vl(sep, mem);

        return mem.back().back();
    }
};

int main() {
    print_v(Solution().minDistance("horse", "ros"));
}
