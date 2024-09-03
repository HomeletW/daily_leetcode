/**
 * 114. Flatten Binary Tree to Linked List
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list
 */

#include "my_util.hpp"
#include "my_tree_node.hpp"

using TreeNode = TreeNode_generic<int>;

using namespace std;

class Solution {
public:
    void flatten(TreeNode *root) {
        if (root == nullptr) {
            return;
        }

        print_vl(sep, *root);
        flatten_rec(root);
        print_v(*root);
    }

    // return end, begin is always node itself
    TreeNode *flatten_rec(TreeNode *node) {
        assert(node != nullptr);

        TreeNode *leftSubtree = node->left, *rightSubtree = node->right;
        node->left = node->right = nullptr;

        TreeNode *end = node;
        if (leftSubtree != nullptr) {
            end->right = leftSubtree;
            end = flatten_rec(leftSubtree);
        }

        if (rightSubtree != nullptr) {
            end->right = rightSubtree;
            end = flatten_rec(rightSubtree);
        }

        return end;
    }
};

class Solution_inorder_traversal {
public:
    void flatten(TreeNode *root) {
        if (root == nullptr) {
            return;
        }

        print_vl(sep, *root);
        auto p = flatten_rec(root);
        print_v(*p.first);
    }

    // return begin and end
    pair<TreeNode *, TreeNode *> flatten_rec(TreeNode *node) {
        assert(node != nullptr);

        TreeNode *leftSubtree = node->left, *rightSubtree = node->right;
        node->left = node->right = nullptr;

        pair<TreeNode *, TreeNode *> ret;
        if (leftSubtree != nullptr) {
            auto flattenLeft = flatten_rec(leftSubtree);
            flattenLeft.second->right = node;
            ret.first = flattenLeft.first;
        } else {
            ret.first = node;
        }

        if (rightSubtree != nullptr) {
            auto flattenRight = flatten_rec(rightSubtree);
            node->right = flattenRight.first;
            ret.second = flattenRight.second;
        } else {
            ret.second = node;
        }

        return ret;
    }
};

int main() {
    auto a = make_tree_node(-1, {1, 2, 5, 3, 4, -1, 6});
    Solution().flatten(a.get());
}
