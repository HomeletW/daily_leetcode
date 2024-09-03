/**
 * 173. Binary Search Tree Iterator
 * https://leetcode.com/problems/binary-search-tree-iterator
 */

#include "my_util.hpp"
#include "my_tree_node.hpp"

using TreeNode = TreeNode_generic<int>;

using namespace std;

class BSTIterator {
    vector<TreeNode *> stack;

public:
    BSTIterator(TreeNode *root) : stack{} {
        // iterate to the minimum entry
        TreeNode *curr = root;
        while (curr != nullptr) {
            stack.push_back(curr);
            curr = curr->left;
        }
    }

    int next() {
        assert(hasNext());
        TreeNode *curr = stack.back(), *next = curr->right;
        stack.pop_back();

        // left side has been explored, try go to right
        while (next != nullptr) {
            stack.push_back(next);
            next = next->left;
        }

        return curr->val;
    }

    bool hasNext() {
        return !stack.empty();
    }
};

void test1() {
    auto n = make_tree_node(-1, {7, 3, 15, -1, -1, 9, 20});
    print_v(*n);
    BSTIterator bSTIterator{n.get()};
    print_v(bSTIterator.next());    // return 3
    print_v(bSTIterator.next());    // return 7
    print_v(bSTIterator.hasNext()); // return True
    print_v(bSTIterator.next());    // return 9
    print_v(bSTIterator.hasNext()); // return True
    print_v(bSTIterator.next());    // return 15
    print_v(bSTIterator.hasNext()); // return True
    print_v(bSTIterator.next());    // return 20
    print_v(bSTIterator.hasNext()); // return False
}

int main() {
    test1();
}
