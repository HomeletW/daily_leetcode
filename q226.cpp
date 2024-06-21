/**
 * 226. Invert Binary Tree
 * https://leetcode.com/problems/invert-binary-tree
 */

#include "my_util.hpp"
#include "my_tree_node.hpp"

using namespace std;

using TreeNode = TreeNode_generic<int>;

class Solution {
public:
    TreeNode *invertTree(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        } else {
            auto left = root->left;
            root->left = invertTree(root->right);
            root->right = invertTree(left);
            return root;
        }
    }
};

int main() {
    auto a = make_tree_node(-1, {4, 2, 7, 1, 3, 6, 9});
    print_v(*a);
    print_v(*Solution().invertTree(a.get()));
}
