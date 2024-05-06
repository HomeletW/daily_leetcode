/**
 *
 */

#include "my_util.hpp"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}

    friend ostream &operator<<(ostream &os, const ListNode &node);

};

ostream &operator<<(ostream &os, const ListNode &node) {
    print(node.val, " -> ");
    if (node.next != nullptr) {
        os << *node.next;
    } else {
        os << "END";
    }
    return os;
}

class Solution {
public:
    void deleteNode(ListNode *node) {
        if (node == nullptr) {
            return;
        }

        while (node->next != nullptr) {
            node->val = node->next->val;
            if (node->next->next == nullptr) {
                // next was the old tail, so I am the new tail
                node->next->val = -1;   // for sanity check, set val to -1
                node->next = nullptr;
                break;
            } else {
                node = node->next;
            }
        }
    }
};

int main() {
    ListNode n1{1}, n2{2}, n3{3}, n4{4}, n5{5}, n6{6}, n7{7};
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;
    n7.next = nullptr;
    print_var(n1);
    Solution().deleteNode(&n3);
    print_var(n1);
    Solution().deleteNode(&n2);
    print_var(n1);
    Solution().deleteNode(&n4);
    print_var(n1);
    Solution().deleteNode(&n1);
    print_var(n1);
}
