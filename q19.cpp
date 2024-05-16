/**
 * 19. Remove Nth Node From End of List
 * https://leetcode.com/problems/remove-nth-node-from-end-of-list
 */

#include "my_util.hpp"
#include "my_list_node.hpp"
#include "my_preprocessor_util.hpp"

using namespace std;

using ListNode = ListNode_generic<int>;

class Solution {
public:
    // Another idea is to keep to pointers with n element apart
    // when the first pointer reaches the end, the second pointer
    // points to where we should do the removal. (O(n) time, O(1) space)

    // Current approach is to recurse to the end, and then backtrack
    // until we reached the nth element from end.
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummyHead{-1, head};
        removeNthFromEnd_rec(&dummyHead, n);
        return dummyHead.next;
    }

    int removeNthFromEnd_rec(ListNode *head, int n) {
        if (head == nullptr) {
            return 0;
        } else {
            int count = removeNthFromEnd_rec(head->next, n);
            if (count == n) {
                // do the remove
                if (head->next != nullptr) {
                    head->next = head->next->next;
                }
            }
            return count + 1;
        }
    }
};

void test1() {
    // 342
//    ListNode n5{5}, n4{4, &n5}, n3{3, &n4}, n2{2, &n3}, n1{1, &n2};
    make_list_node(int, n, 1, 2, 3, 4, 5);

    print_varl(sep, n0);
    auto res = Solution().removeNthFromEnd(&n0, 2);
    if (res != nullptr) {
        print_var(*res);
    } else {
        print_var("res: null");
    }
}

void test2() {
    ListNode n1{1};
    n1.next = nullptr;

    print_varl(sep, n1);
    auto res = Solution().removeNthFromEnd(&n1, 1);
    if (res != nullptr) {
        print_var(*res);
    } else {
        print_var("res: null");
    }
}

void test3() {
    ListNode n1{1}, n2{2};
    n1.next = &n2;
    n2.next = nullptr;

    print_varl(sep, n1);
    auto res = Solution().removeNthFromEnd(&n1, 1);
    if (res != nullptr) {
        print_var(*res);
    } else {
        print_var("res: null");
    }
}

void test4() {
    ListNode n1{1}, n2{2};
    n1.next = &n2;
    n2.next = nullptr;

    print_varl(sep, n1);
    auto res = Solution().removeNthFromEnd(&n1, 0);
    if (res != nullptr) {
        print_var(*res);
    } else {
        print_var("res: null");
    }
}

int main() {
    test1();
    test2();
    test3();
    test4();
}
