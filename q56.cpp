/**
 * 56. Merge Intervals
 * https://leetcode.com/problems/merge-intervals
 *
 * Date: 2025-01-08
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        // sort by starting position,
        // similar to q452
        std::sort(intervals.begin(), intervals.end(), [](const auto &p1, const auto &p2) {
            return p1[0] < p2[0];
        });
        print_v(intervals);
        vector<vector<int>> merged_intervals;
        int current_pos = intervals[0][1], last_pos = intervals[0][0];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] > current_pos) {
                // record the last run
                merged_intervals.emplace_back(vector<int>{last_pos, current_pos});
                // start a new run
                last_pos = intervals[i][0];
                current_pos = intervals[i][1];
            } else {
                // extend the last run
                last_pos = min(last_pos, intervals[i][0]);
                current_pos = max(current_pos, intervals[i][1]);
            }
        }
        // record the last run
        merged_intervals.emplace_back(vector<int>{last_pos, current_pos});
        return merged_intervals;
    }
};

int main() {
    vector<vector<int>> vec{{2, 3},
                            {4, 5},
                            {6, 7},
                            {8, 9},
                            {1, 10}};
    print_v(Solution().merge(vec));
}
