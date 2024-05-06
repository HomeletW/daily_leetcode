/**
 *
 */

#include "my_util.hpp"

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if ((p == nullptr) ^ (q == nullptr)) {
            // either p && !q or !p && q
            return false;
        } else if (p == nullptr && q == nullptr) {
            return true;
        } else {
            return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
};

void test1() {
    TreeNode a1{1}, a2{2}, a3{3}, a4{4}, a5{5}, a6{6}, a7{7};
    TreeNode b1{1}, b2{2}, b3{3}, b4{4}, b5{5}, b6{6}, b7{7};
    a1.left = &a2;
    a1.right = &a3;
    a2.left = &a4;
    a2.right = &a5;
    a3.left = &a6;
    a3.right = &a7;

    b1.left = &b2;
    b1.right = &b3;
    b2.left = &b4;
    b2.right = &b5;
    b3.left = &b6;
    b3.right = &b7;

    print_line("Test1: ", Solution().isSameTree(&a1, &b1));
}

void test2() {
    TreeNode a1{1}, a2{2}, a3{3}, a4{4}, a5{5}, a6{6}, a7{7};
    TreeNode b1{1}, b2{2}, b3{3}, b4{4}, b5{5}, b6{6}, b7{7};
    a1.left = &a3;
    a1.right = &a2;
    a2.left = &a4;
    a2.right = &a5;
    a3.left = &a6;
    a3.right = &a7;

    b1.left = &b2;
    b1.right = &b3;
    b2.left = &b4;
    b2.right = &b5;
    b3.left = &b6;
    b3.right = &b7;

    print_line("Test2: ", Solution().isSameTree(&a1, &b1));
}

void test3() {
    TreeNode a1{1}, a2{2}, a3{3}, a4{4}, a5{5}, a6{6}, a7{7};
    TreeNode b1{1}, b2{2}, b3{3}, b4{4}, b5{5}, b6{6}, b7{7};
    a1.left = &a2;
    a1.right = &a3;
    a2.left = &a4;
    a2.right = &a5;

    b1.left = &b2;
    b1.right = &b3;
    b2.left = &b6;
    b2.right = &b7;

    print_line("Test3: ", Solution().isSameTree(&a1, &b1));
}

int main() {
    test1();
    test2();
    test3();
}