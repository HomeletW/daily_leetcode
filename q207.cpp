/**
 * 207. Course Schedule
 * https://leetcode.com/problems/course-schedule
 */

#include "my_util.hpp"

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        // Idea: topological sort (detect cycle)
        // Dependencies represents edges of the graph
        // Record the vertices with no incoming edges in a stack
        // Repeat while stack not empty:
        //      Remove the course on top of the stack from graph
        // Cycles would prevent the graph to become empty.

        vector<vector<int>> edges(numCourses, vector<int>{});
        vector<int> numIncoming(numCourses, 0);  // index -> num incoming edge

        // construct graph
        for (const auto &pair: prerequisites) {
            edges[pair[1]].push_back(pair[0]);
            ++numIncoming[pair[0]];
        }

        // collect vertices with no incoming
        vector<int> stack;
        for (int i = 0; i < numCourses; ++i) {
            if (numIncoming[i] == 0) {
                stack.push_back(i);
            }
        }

        print_varl(sep, edges, numIncoming, stack);

        // peal off vertices with no incoming
        while (!stack.empty()) {
            int toBeRemoved = stack.back();
            stack.pop_back();

            for (int i: edges[toBeRemoved]) {
                if (--numIncoming[i] == 0) {
                    stack.push_back(i);
                }
            }
        }

        print_vl(h2("after"), numIncoming);

        // check if there are any graphs that is not zero
        for (int i = 0; i < numCourses; ++i) {
            if (numIncoming[i] != 0) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    vector<vector<int>> pre1{{1, 0}}, pre2{{1, 0},
                                           {0, 1}};
    print_var(Solution().canFinish(2, pre1));
    print_var(Solution().canFinish(2, pre2));
}
