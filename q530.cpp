/**
 * 530. Minimum Absolute Difference in BST
 * https://leetcode.com/problems/minimum-absolute-difference-in-bst
 */

#include "my_util.hpp"

using namespace std;

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
    int getMinimumDifference(TreeNode *root) {
        int minDiff = numeric_limits<int>::max();
        getMinimumDifference_rec(root, minDiff);
        return minDiff;
    }

    // return min, max
    pair<int, int> getMinimumDifference_rec(TreeNode *root, int &minDiff) {
        assert(root != nullptr);

        int minVal, maxVal;
        if (root->left != nullptr) {
            auto leftMinMax = getMinimumDifference_rec(root->left, minDiff);
            minDiff = min(minDiff, root->val - leftMinMax.second);
            minVal = leftMinMax.first;
        } else {
            minVal = root->val;
        }

        if (root->right != nullptr) {
            auto rightMinMax = getMinimumDifference_rec(root->right, minDiff);
            minDiff = min(minDiff, rightMinMax.first - root->val);
            maxVal = rightMinMax.second;
        } else {
            maxVal = root->val;
        }

        return {minVal, maxVal};
    }
};

int main() {

}
