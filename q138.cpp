/**
 * 138. Copy List with Random Pointer
 * https://leetcode.com/problems/copy-list-with-random-pointer
 *
 * Date: 2024-09-08
 */

#include "my_util.hpp"
#include "my_list_node.hpp"

using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node() : Node(0) {}

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }

    Node(int val, Node *next) : val{val}, next{next}, random{nullptr} {}
};

static_assert(ListNodeLike<Node> && Printable < Node > );

class Solution {
public:
    Node *copyRandomList(Node *head) {
        std::unordered_map < Node * , Node * > newMap; // maps old -> new
        Node *v = head;
        while (v != nullptr) {
            newMap[v] = new Node(v->val);
            v = v->next;
        }
        Node dummyHead{-1}, *newHead = &dummyHead;
        v = head;
        while (v != nullptr) {
            Node *currHead = newMap[v];
            if (v->random != nullptr) {
                currHead->random = newMap[v->random];
            }
            newHead->next = currHead;
            newHead = newHead->next;
            v = v->next;
        }
        return dummyHead.next;
    }
};

int main() {
    make_list_node_custom_type(Node, n, 7, 13, 11, 10, 1);
    n0.random = nullptr;
    n1.random = &n0;
    n2.random = &n4;
    n3.random = &n2;
    n4.random = &n0;

    print_v(n0);
    print_v(*Solution().copyRandomList(&n0));
}
