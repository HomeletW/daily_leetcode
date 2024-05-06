/**
 *
 */

#include "vector"
#include "list"
#include "iostream"
#include "my_util.hpp"

using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        vector<vector<int>> result{};
        list<vector<int>> queue{};
        for (int beg: graph[0]) {
            queue.emplace_back(vector{0, beg});
        }
        while (!queue.empty()) {
            vector<int> path = queue.front();
            queue.pop_front();
            int endPoint = path.back();
            if (endPoint == graph.size() - 1) {
                result.push_back(std::move(path));
            } else {
                // expand the path
                for (int nextPoint: graph[endPoint]) {
                    vector<int> &newPath = queue.emplace_back(path.begin(), path.end());
                    newPath.push_back(nextPoint);
                }
            }
        }
        return result;
    }
};

int main() {
//    vector<vector<int>> graph = {{4,3,1},{3,2,4},{3},{4},{}};
    vector<vector<int>> graph = {{1, 2},
                                 {3},
                                 {3},
                                 {}};
    auto result = Solution().allPathsSourceTarget(graph);
//    for_each(std::ranges::ref_view(result), print_range<decltype(result[0])>);
    print(result);
    print("i: ", {123, 324});
}