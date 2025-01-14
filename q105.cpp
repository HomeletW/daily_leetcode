/**
 * 105. Construct Binary Tree from Preorder and Inorder Traversal
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal
 *
 * Date: 2025-01-11
 */

#include "my_util.hpp"
#include "my_tree_node.hpp"

using TreeNode = TreeNode_generic<int>;

using namespace std;

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree_rec(preorder, inorder, 0, 0, inorder.size());
    }

    TreeNode *buildTree_rec(vector<int> &preorder, vector<int> &inorder,
                            int preorder_idx, int inorder_beg, int inorder_end) {
        if (inorder_beg == inorder_end) {
            return nullptr;
        }
        // the substructure is as follows:
        // The preorder[0] would be the head of the tree,
        // then we find the index of it in inorder, which separates inorder
        // into two sub arrays for the left and right subtree
        TreeNode *root = new TreeNode(preorder[preorder_idx]);
        print_var_oneline(preorder_idx, inorder_beg, inorder_end, root->val);
        if (inorder_beg + 1 == inorder_end) {
            return root;
        }
        auto iter = std::find(inorder.begin() + inorder_beg, inorder.begin() + inorder_end, root->val);
        assert(iter != inorder.end());
        int inorder_mid = std::distance(inorder.begin(), iter);
        int preorder_left_idx = preorder_idx + 1;
        int preorder_right_idx = preorder_idx + 1 + inorder_mid - inorder_beg;
        root->left = buildTree_rec(preorder, inorder, preorder_left_idx, inorder_beg, inorder_mid);
        root->right = buildTree_rec(preorder, inorder, preorder_right_idx, inorder_mid + 1, inorder_end);
        return root;
    }
};

int main() {
    vector<int> preorder_1{3, 9, 20, 15, 7};
    vector<int> inorder_1{9, 3, 15, 20, 7};
    print_v(preorder_1, inorder_1);
    print_v(*Solution().buildTree(preorder_1, inorder_1));
    vector<int> preorder_2{-1};
    vector<int> inorder_2{-1};
    print_v(preorder_2, inorder_2);
    print_v(*Solution().buildTree(preorder_2, inorder_2));
    vector<int> preorder_3{1, 2};
    vector<int> inorder_3{2, 1};
    print_v(preorder_3, inorder_3);
    print_v(*Solution().buildTree(preorder_3, inorder_3));
}
