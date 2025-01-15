/**
 * 103. Binary Tree Zigzag Level Order Traversal
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal
 *
 * Date: 2025-01-14
 */

#include "my_util.hpp"
#include "my_tree_node.hpp"

using TreeNode = TreeNode_generic<int>;

using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> result;
        deque<TreeNode *> queue{root};
        size_t last_level_size = queue.size();
        bool zigzag = false;
        while (!queue.empty()) {
            vector<int> level_result;
            level_result.reserve(last_level_size);
            for (int i = 0; i < last_level_size; ++i) {
                TreeNode *node = queue.front();
                queue.pop_front();
                level_result.push_back(node->val);
                if (node->left != nullptr) {
                    queue.push_back(node->left);
                }
                if (node->right != nullptr) {
                    queue.push_back(node->right);
                }
            }
            if (zigzag) {
                std::reverse(level_result.begin(), level_result.end());
            }
            zigzag = !zigzag;
            last_level_size = queue.size();
            result.emplace_back(std::move(level_result));
        }
        return result;
    }
};

int main() {
    auto a = make_tree_node(-1, {3, 9, 20, -1, -1, 15, 7});
    auto b = make_tree_node(-1, {1});
    auto c = make_tree_node(-1, {});
    print_v(*a, Solution().zigzagLevelOrder(a.get()));
    print_v(*b, Solution().zigzagLevelOrder(b.get()));
    print_v(Solution().zigzagLevelOrder(c.get()));
}
