/**
 * 133. Clone Graph
 * https://leetcode.com/problems/clone-graph
 */

#include "my_util.hpp"

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node *> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node *cloneGraph(Node *node) {
        if (node == nullptr) {
            return nullptr;
        }

        unordered_map<Node *, Node *> mem;
        return cloneGraph_rec(node, mem);
    }

    Node *cloneGraph_rec(Node *node, unordered_map<Node *, Node *> &mem) {
        auto iter = mem.find(node);
        if (iter != mem.end()) {
            return iter->second;
        }

        Node *clone = new Node();
        mem[node] = clone;

        clone->val = node->val;
        for (Node *neighbor: node->neighbors) {
            clone->neighbors.push_back(cloneGraph_rec(neighbor, mem));
        }

        return clone;
    }
};

int main() {

}