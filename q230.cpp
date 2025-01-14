/**
 * 230. Kth Smallest Element in a BST
 * https://leetcode.com/problems/kth-smallest-element-in-a-bst
 *
 * Date: 2025-01-11
 */

#include "my_util.hpp"
#include "my_tree_node.hpp"

using TreeNode = TreeNode_generic<int>;

using namespace std;

class Solution {
public:
    int kthSmallest(TreeNode *root, int k) {
        vector<TreeNode *> stack{root};
        // go to the very left (the smallest)
        while (stack.back()->left != nullptr) {
            stack.push_back(stack.back()->left);
        }
        // start in-order traversal
        while (!stack.empty()) {
            TreeNode *node = stack.back();
            stack.pop_back();
            if (k == 1) {
                return node->val;
            } else {
                --k;
            }
            if (node->right != nullptr) {
                stack.push_back(node->right);
                // go to the very left (the smallest)
                while (stack.back()->left != nullptr) {
                    stack.push_back(stack.back()->left);
                }
            }
        }
        return -1;  // shouldn't be here
    }
};

int main() {
    std::setlocale(LC_ALL, "");
    std::wcout.imbue(std::locale());
    auto t1 = make_tree_node(-1, {3, 1, 4, -1, 2});
    auto t2 = make_tree_node(-1, {5, 3, 6, 2, 4, -1, -1, 1});
//    pretty_print_tree<BoxedTreeNodePrettyPrintConfig, TreeNode, wchar_t>(std::wcout, t1.get());
//    pretty_print_tree<BoxedTreeNodePrettyPrintConfig, TreeNode, wchar_t>(std::wcout, t2.get());
    print_v(*t1, Solution().kthSmallest(t1.get(), 1));
    print_v(*t1, Solution().kthSmallest(t1.get(), 3));
    print_v(*t2, Solution().kthSmallest(t2.get(), 3));
}
