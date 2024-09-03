/**
 * 148. Sort List
 * https://leetcode.com/problems/sort-list
 */

#include "my_util.hpp"
#include "my_list_node.hpp"

using ListNode = ListNode_generic<int>;

using namespace std;

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (head == nullptr) {
            return nullptr;
        } else if (head->next == nullptr) {
            return head;
        }

        // segregate the list into two
        ListNode *fast = head, *slow = head, *slowPrev = nullptr;
        while (fast != nullptr && fast->next != nullptr) {
            slowPrev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        slowPrev->next = nullptr;

        ListNode *list1 = sortList(head);
        ListNode *list2 = sortList(slow);
        return sortList_merge(list1, list2);
    }

    ListNode *sortList_merge(ListNode *head1, ListNode *head2) {
        ListNode dummyHead{-1, nullptr}, *tail = &dummyHead;
        while (head1 != nullptr && head2 != nullptr) {
            if (head1->val < head2->val) {
                tail->next = head1;
                tail = head1;
                head1 = head1->next;
            } else {
                tail->next = head2;
                tail = head2;
                head2 = head2->next;
            }
            tail->next = nullptr;
        }
        if (head1 != nullptr) {
            tail->next = head1;
        }
        if (head2 != nullptr) {
            tail->next = head2;
        }
        return dummyHead.next;
    }
};

int main() {
    make_list_node(int, a, 4, 2, 1, 3);
    make_list_node(int, b, -1, 5, 3, 4, 0);
    print_v(*Solution().sortList(&a0));
    print_v(*Solution().sortList(&b0));
}
