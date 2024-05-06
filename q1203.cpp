/**
 * 1203. Sort Items by Groups Respecting Dependencies
 * https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/
 */
#include "deque"
#include "my_util.hpp"

using namespace std;

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int> &group, vector<vector<int>> &beforeItems) {
        // idea: topological sort
        // each item belongs to a group (ungrouped item is in it's own group)
        // we need to consider two dependency
        // 1. the item within the same group should respect beforeItem
        // 2. the item within different group makes the group themselves depends on each other
        //
        // the main idea is to use topological sort twice to satisfies the condition that
        // items in the same group must be next to each other

        // make sure unassigned groups are in their own groups
        int totalGroups = m;
        for (int i = 0; i < n; ++i) {
            if (group[i] == -1) {
                // item without a gp belongs to their own group
                group[i] = totalGroups++;
            }
        }

        vector<vector<int>> itemGraph(n);
        vector<int> itemInDegree(n, 0);

        vector<vector<int>> groupGraph(totalGroups);
        vector<int> groupInDegree(totalGroups, 0);

        // construct the graphs
        for (int i = 0; i < n; ++i) {
            const auto &deps = beforeItems[i];
            for (int dep: deps) {
                // add an edge dep -> i in itemGraph, update inDegree accordingly
                itemGraph[dep].push_back(i);
                itemInDegree[i]++;

                // if dep and i belongs to different groups,
                // add an edge group[dep] -> group[i] in groupGraph, update inDegree accordingly
                if (group[i] != group[dep]) {
                    groupGraph[group[dep]].push_back(group[i]);
                    groupInDegree[group[i]]++;
                }
            }
        }

        // topological sort on the two graphs
        vector<int> itemOrder = topologicalSort(itemGraph, itemInDegree);
        vector<int> groupOrder = topologicalSort(groupGraph, groupInDegree);

        // if any of the graph contained cycle, there are no solution
        if (itemOrder.empty() || groupOrder.empty()) {
            return {};
        }

        // construct each group's order, because all item in the same group must be next to each other
        vector<vector<int>> orderedGroup(totalGroups);
        for (int item: itemOrder) {
            orderedGroup[group[item]].push_back(item);
        }

        // construct the final result
        vector<int> result;
        for (int groupIndex: groupOrder) {
            result.insert(result.end(), orderedGroup[groupIndex].begin(), orderedGroup[groupIndex].end());
        }

        return result;
    }

private:
    vector<int> topologicalSort(const vector<vector<int>> &graph, vector<int> inDegree) {
        vector<int> order;
        vector<int> stack;

        // push the zero inDegree into the stack
        for (int i = 0; i < graph.size(); ++i) {
            if (inDegree[i] == 0) {
                stack.push_back(i);
            }
        }

        while (!stack.empty()) {
            int i = stack.back();
            order.push_back(i);
            stack.pop_back();

            // peal off the dependency by one, and when it depends on nothing
            // push it to stack
            for (int dep: graph[i]) {
                if (--inDegree[dep] == 0) {
                    stack.push_back(dep);
                }
            }
        }

        // in the end, if there is no cycle in the graph, everything should added to order.
        // but, cycles prevent the inDegree to reach zero, therefore never added to order.
        if (order.size() == graph.size()) {
            return order;
        } else {
            return {};
        }
    }
};

int main() {
    vector<int> group{2, 0, -1, 3, 0};
    vector<vector<int>> beforeItems{{2, 1, 3},
                                    {2, 4},
                                    {},
                                    {},
                                    {}};
    auto res = Solution().sortItems(5, 5, group, beforeItems);
    print_range(res);
}