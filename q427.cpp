/**
 * 427. Construct Quad Tree
 * https://leetcode.com/problems/construct-quad-tree
 *
 * Date: 2025-01-07
 */

#include "my_util.hpp"

using namespace std;


// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


class Solution {
public:
    Node *construct(vector<vector<int>> &grid) {
        return construct_rec(grid, 0, grid[0].size(), 0, grid.size());
    }

    int all_same(vector<vector<int>> &grid, int x1, int x2, int y1, int y2) {
        int val = grid[y1][x1];
        for (int y = y1; y < y2; ++y) {
            for (int x = x1; x < x2; ++x) {
                if (grid[y][x] != val) {
                    return -1;
                }
            }
        }
        return val;
    }

    Node *construct_rec(vector<vector<int>> &grid, int x1, int x2, int y1, int y2) {
        int width = x2 - x1, height = y2 - y1;
        if (width == 0 || height == 0) {
            return nullptr;
        } else if (width == 1 && height == 1) {
            // base case
            int val = grid[y1][x1];
            return new Node(val, true);
        } else {
            int val = all_same(grid, x1, x2, y1, y2);
            if (val == -1) {
                // divide case
                int center_x = x1 + width / 2;
                int center_y = y1 + height / 2;
                Node *node = new Node();
                node->isLeaf = false;
                node->topLeft = construct_rec(grid, x1, center_x, y1, center_y);
                node->topRight = construct_rec(grid, center_x, x2, y1, center_y);
                node->bottomLeft = construct_rec(grid, x1, center_x, center_y, y2);
                node->bottomRight = construct_rec(grid, center_x, x2, center_y, y2);
                return node;
            } else {
                return new Node(val, true);
            }
        }
    }
};

int main() {

}
