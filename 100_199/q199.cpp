/**
 * 199. Binary Tree Right Side View
 * https://leetcode.com/problems/binary-tree-right-side-view
 */

#include "my_util.hpp"
#include "my_tree_node.hpp"

using namespace std;

using TreeNode = TreeNode_generic<int>;

class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }

        vector<int> result;
        deque<TreeNode *> stack{root};
        while (!stack.empty()) {
            result.push_back(stack.back()->val);
            int thisLayer = stack.size();
            for (int i = 0; i < thisLayer; ++i) {
                TreeNode *top = stack.front();
                stack.pop_front();
                if (top->left != nullptr) {
                    stack.push_back(top->left);
                }
                if (top->right != nullptr) {
                    stack.push_back(top->right);
                }
            }
        }
        if (root != nullptr)
            print_varl(sep, *root);
        else
            print_varl(sep, "nullptr");
        return result;
    }
};


int main() {
    auto a = make_tree_node(-1, {1, 2, 3, -1, 5, -1, 4});
    auto b = make_tree_node(-1, {1, -1, 3});
    auto c = make_tree_node(-1, {});
    print_v(Solution().rightSideView(a.get()));
    print_v(Solution().rightSideView(b.get()));
    print_v(Solution().rightSideView(c.get()));
}
