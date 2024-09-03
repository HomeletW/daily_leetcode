/**
 * 2. Add Two Numbers
 * https://leetcode.com/problems/add-two-numbers
 */

#include "my_util.hpp"
#include "my_list_node.hpp"

using ListNode = ListNode_generic<int>;

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        return addTwoNumbers_rec(l1, l2, 0);
    }

    ListNode *addTwoNumbers_rec(ListNode *l1, ListNode *l2, int carry) {
        if (l1 == nullptr && l2 == nullptr) {
            if (carry == 0) {
                return nullptr;
            } else {
                return new ListNode{carry};
            }
        }

        ListNode *curr = new ListNode{};
        if (l1 == nullptr) {
            int val = l2->val + carry;
            carry = val / 10;
            val = val % 10;
            curr->val = val;
            curr->next = addTwoNumbers_rec(nullptr, l2->next, carry);
        } else if (l2 == nullptr) {
            int val = l1->val + carry;
            carry = val / 10;
            val = val % 10;
            curr->val = val;
            curr->next = addTwoNumbers_rec(l1->next, nullptr, carry);
        } else {
            int val = l1->val + l2->val + carry;
            carry = val / 10;
            val = val % 10;
            curr->val = val;
            curr->next = addTwoNumbers_rec(l1->next, l2->next, carry);
        }

        return curr;
    }
};

void test1() {
    // 342
    ListNode n1{2}, n2{4}, n3{3};
    n1.next = &n2;
    n2.next = &n3;
    n3.next = nullptr;

    // 456
    ListNode k1{5}, k2{6}, k3{4};
    k1.next = &k2;
    k2.next = &k3;
    k3.next = nullptr;

    print_varl(sep, n1, k1);
    auto res = Solution().addTwoNumbers(&n1, &k1);
    print_varl(sep, *res);
}

void test2() {
    // 0
    ListNode n1{0};
    n1.next = nullptr;

    // 0
    ListNode k1{0};
    k1.next = nullptr;

    print_varl(sep, n1, k1);
    auto res = Solution().addTwoNumbers(&n1, &k1);
    print_varl(sep, *res);
}

void test3() {
    // 9999999
    ListNode n1{9}, n2{9}, n3{9}, n4{9}, n5{9}, n6{9}, n7{9};
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;
    n7.next = nullptr;

    // 9999
    ListNode k1{9}, k2{9}, k3{9}, k4{9};
    k1.next = &k2;
    k2.next = &k3;
    k3.next = &k4;
    k4.next = nullptr;

    print_varl(sep, n1, k1);
    auto res = Solution().addTwoNumbers(&n1, &k1);
    print_varl(sep, *res);
}

int main() {
    test1();
    test2();
    test3();
}
