/**
 * Given an integer n, return all the structurally unique BST's (binary search trees),
 * which has exactly n nodes of unique values from 1 to n. Return the answer in any order.
 * https://leetcode.com/problems/unique-binary-search-trees-ii/
 */

#include <vector>

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
    vector<TreeNode*> generateTrees(int n) {
        return constructTree(1, n);
    }
private:
    vector<TreeNode*> constructTree(int min, int max)
    {
        if (min == max)
        {
            return {new TreeNode{min}};
        }
        else if (min > max)
        {
            return {};
        }
        else
        {
            vector<TreeNode*> result{};
            for (int v = min; v <= max; ++v)
            {
                vector<TreeNode*> left = constructTree(min, v - 1);
                vector<TreeNode*> right = constructTree(v + 1, max);
                if (left.empty() && !right.empty())
                {
                    for (TreeNode* rightNode : right)
                    {
                        result.push_back(new TreeNode(v, nullptr, rightNode));
                    }
                }
                else if (!left.empty() && right.empty())
                {
                    for (TreeNode* leftNode : left)
                    {
                        result.push_back(new TreeNode(v, leftNode, nullptr));
                    }
                }
                else
                {
                    for (TreeNode* leftNode : left)
                    {
                        for (TreeNode* rightNode : right)
                        {
                            result.push_back(new TreeNode(v, leftNode, rightNode));
                        }
                    }
                }
            }
            return result;
        }
    }
};

int main()
{

}