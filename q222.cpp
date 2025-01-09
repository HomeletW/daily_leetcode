/**
 * 222. Count Complete Tree Nodes
 * https://leetcode.com/problems/count-complete-tree-nodes
 *
 * Date: 2025-01-09
 */

#include "my_util.hpp"
#include "my_tree_node.hpp"

using namespace std;

using TreeNode = TreeNode_generic<int>;

class Solution {
public:
    int countNodes(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        TreeNode *left = root, *right = root;
        int left_height = 0, right_height = 0;

        while (left != nullptr) {
            ++left_height;
            left = left->left;
        }

        while (right != nullptr) {
            ++right_height;
            right = right->right;
        }

        if (left_height == right_height) {
            // is a complete tree
            return std::pow(2, left_height) - 1;
        } else {
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
    }
};

int main() {
    auto p = make_tree_node<int>(-1, {1, 2, 3, 4, 5, 6, -1});
    print_v(*p, Solution().countNodes(p.get()));
}
