/**
 * 106. Construct Binary Tree from Inorder and Postorder Traversal
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
 *
 * Date: 2025-01-12
 */

#include "my_util.hpp"
#include "my_tree_node.hpp"

using TreeNode = TreeNode_generic<int>;

using namespace std;

class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree_rec(inorder, postorder, postorder.size() - 1, 0, inorder.size());
    }

    TreeNode *buildTree_rec(vector<int> &inorder, vector<int> &postorder,
                            int postorder_idx, int inorder_beg, int inorder_end) {
        if (inorder_beg == inorder_end) {
            return nullptr;
        }
        // the substructure is as follows:
        // The preorder[-1] would be the head of the tree,
        // then we find the index of it in inorder, which separates inorder
        // into two sub arrays for the left and right subtree
        TreeNode *root = new TreeNode(postorder[postorder_idx]);
        print_var_oneline(postorder_idx, inorder_beg, inorder_end, root->val);
        if (inorder_beg + 1 == inorder_end) {
            return root;
        }
        auto iter = std::find(inorder.begin() + inorder_beg, inorder.begin() + inorder_end, root->val);
        assert(iter != inorder.end());
        int inorder_mid = std::distance(inorder.begin(), iter);
        int postorder_right_idx = postorder_idx - 1;
        int postorder_left_idx = postorder_idx - 1 - (inorder_end - inorder_mid - 1);
        root->right = buildTree_rec(inorder, postorder, postorder_right_idx, inorder_mid + 1, inorder_end);
        root->left = buildTree_rec(inorder, postorder, postorder_left_idx, inorder_beg, inorder_mid);
        return root;
    }
};

int main() {
    vector<int> inorder_1{9, 3, 15, 20, 7};
    vector<int> postorder_1{9, 15, 7, 20, 3};
    print_v(inorder_1, postorder_1);
    print_v(*Solution().buildTree(inorder_1, postorder_1));
    vector<int> inorder_2{-1};
    vector<int> postorder_2{-1};
    print_v(inorder_2, postorder_2);
    print_v(*Solution().buildTree(inorder_2, postorder_2));
    vector<int> inorder_3{2, 1};
    vector<int> postorder_3{2, 1};
    print_v(inorder_3, postorder_3);
    print_v(*Solution().buildTree(inorder_3, postorder_3));
}
