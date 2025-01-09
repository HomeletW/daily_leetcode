/**
 * 452. Minimum Number of Arrows to Burst Balloons
 * https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons
 *
 * Date: 2025-01-08
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>> &points) {
        // sort by the ending order
        std::sort(points.begin(), points.end(), [](const auto &p1, const auto &p2) {
            return p1[1] < p2[1];
        });
        // the idea is that every balloon must be shot down with an arrow
        int arrow_count = 1;
        int arrow_pos = points[0][1];
        for (int i = 1; i < points.size(); ++i) {
            if (points[i][0] <= arrow_pos) {
                continue;
            }
            arrow_count += 1;
            arrow_pos = points[i][1];
        }
        return arrow_count;
    }
};

int main() {

}
