/**
 * 101. Symmetric Tree
 * https://leetcode.com/problems/symmetric-tree
 *
 * Date: 2024-08-29
 */

#include "my_util.hpp"
#include "my_tree_node.hpp"

using namespace std;

using TreeNode = TreeNode_generic<int>;

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }

        deque<TreeNode *> queue{root};
        int level_size = 1;
        while (!queue.empty()) {
            // push the new level in
            for (int i = 0; i < level_size; ++i) {
                TreeNode *head = queue.front();
                if (head != nullptr) {
                    queue.push_back(head->left);
                    queue.push_back(head->right);
                }
                queue.pop_front();
            }
            level_size = queue.size();
            assert(level_size % 2 == 0);

            // check the symmetry of the new level
            int left = 0;
            int right = level_size - 1;
            while (left < right) {
                TreeNode* leftNode = queue.at(left);
                TreeNode* rightNode = queue.at(right);
                if (!node_equal(leftNode, rightNode)) {
                    return false;
                }
                ++left;
                --right;
            }

        }
        return true;
    }

    bool node_equal(TreeNode* n1, TreeNode* n2) {
        if ((n1 == nullptr) != (n2 == nullptr)) {
            return false;
        } else if (n1 == nullptr) {
            assert(n2 == nullptr);
            return true;
        } else {
            return n1->val == n2->val;
        }
    }
};

int main() {
    auto tree1 = make_tree_node(-1, {1,
                                     2, 2,
                                     3, 4, 4, 3,
                                     5, 6, 7, 8, 8, 7, 6, 5});
    auto tree2 = make_tree_node(-1, {1,
                                     2, 2,
                                     -1, 3, -1, 3});
    print_v(*tree1, *tree2);
    print_v(Solution().isSymmetric(tree1.get()));
    print_v(Solution().isSymmetric(tree2.get()));
}
