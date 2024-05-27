/**
 * 21. Merge Two Sorted Lists
 * https://leetcode.com/problems/merge-two-sorted-lists
 */

#include "my_util.hpp"
#include "my_list_node.hpp"

using namespace std;

using ListNode = ListNode_generic<int>;

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        // must directly merge the two list, without copying

        ListNode dummyHead{-1, nullptr}, *head = &dummyHead;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                head->next = list1;
                head = list1;
                list1 = list1->next;
            } else {
                head->next = list2;
                head = list2;
                list2 = list2->next;
            }
        }

        if (list1 != nullptr) {
            head->next = list1;
        }
        if (list2 != nullptr) {
            head->next = list2;
        }

        print_varl(sep, dummyHead);

        return dummyHead.next;
    }

};

int main() {
    make_list_node(int, i, 1, 2, 4);
    make_list_node(int, j, 1, 3, 4);
    print_v(i0, j0);
    print_line(Solution().mergeTwoLists(&i0, &j0));
}
