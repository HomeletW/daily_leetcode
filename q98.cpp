/**
 * 98. Validate Binary Search Tree
 * https://leetcode.com/problems/validate-binary-search-tree
 *
 * Date: 2025-01-13
 */

#include "my_util.hpp"
#include "my_tree_node.hpp"

using TreeNode = TreeNode_generic<int>;

using namespace std;

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return isValidBST_rec(root, nullptr, nullptr);
    }

    bool isValidBST_rec(TreeNode *root, int *left_val, int *right_val) {
        if (root == nullptr) {
            return true;
        } else if ((left_val != nullptr && root->val <= *left_val) ||
                   (right_val != nullptr && root->val >= *right_val)) {
            return false;
        } else {
            return isValidBST_rec(root->left, left_val, &root->val) &&
                   isValidBST_rec(root->right, &root->val, right_val);
        }
    }
};

int main() {
    auto a = make_tree_node(-1, {2, 1, 3});
    auto b = make_tree_node(-1, {5, 1, 4, -1, -1, 3, 6});
    auto c = make_tree_node(-1, {2, 2, 2});
    auto d = make_tree_node(-1, {2147483647});
    auto e = make_tree_node(-1, {2147483647, 2147483647});
    print_v(*a, Solution().isValidBST(a.get()));
    print_v(*b, Solution().isValidBST(b.get()));
    print_v(*c, Solution().isValidBST(c.get()));
    print_v(*d, Solution().isValidBST(d.get()));
    print_v(*e, Solution().isValidBST(e.get()));
}
