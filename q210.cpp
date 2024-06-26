/**
 * 210. Course Schedule II
 * https://leetcode.com/problems/course-schedule-ii/description
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        // use topological sort to determine the courses with no prerequisite
        // then remove them one by one from the graph, the order would be
        // the order the vertices got removed

        // build graph
        vector<int> incomingEdge(numCourses, 0);
        for (const auto &preq: prerequisites) {
            ++incomingEdge[preq[0]];
        }
        print_vl(sep, incomingEdge);

        // find "roots", the vertices with no incoming edges
        vector<int> roots;
        for (int i = 0; i < numCourses; ++i) {
            if (incomingEdge[i] == 0) {
                roots.push_back(i);
            }
        }

        // "peel" roots one by one, and construct order
        int index = 0;
        while (index < numCourses) {
            if (index >= roots.size()) {
                // impossible to do
                return {};
            }
            int i = roots[index];
            for (const auto &preq: prerequisites) {
                if (preq[1] == i) {
                    if (--incomingEdge[preq[0]] == 0) {
                        roots.push_back(preq[0]);
                    }
                }
            }
            ++index;
        }

        return roots;
    }
};

int main() {
    vector<vector<int>> preq1{{1, 0}}, preq2{{1, 0},
                                             {2, 0},
                                             {3, 1},
                                             {3, 2}}, preq3{{0, 1},
                                                            {1, 0}};

    print_v(Solution().findOrder(2, preq1));
    print_v(Solution().findOrder(4, preq2));
    print_v(Solution().findOrder(2, preq3));
}
