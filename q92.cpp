/**
 * 92. Reverse Linked List II
 * https://leetcode.com/problems/reverse-linked-list-ii
 *
 * Date: 2024-07-21
 */

#include "my_util.hpp"
#include "my_list_node.hpp"

using namespace std;

using ListNode = ListNode_generic<int>;

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int left, int right) {
        print_vl(sep);
        ListNode *temp = head;
        for (int i = 1; i < left; ++i) {
            temp = temp->next;
        }
        reverseList(temp, right - left + 1);
        return head;
    }

    void reverseList(ListNode *head, int size) {
        print_vl(h2(), *head, size);
        if (size == 0 || size == 1) {
            return;
        } else if (size == 2) {
            int temp_val = head->val;
            head->val = head->next->val;
            head->next->val = temp_val;
        } else {
            // traverse to the midpoint
            int half = (size + 1) / 2;  // ceil
            ListNode *mid_point = head;
            for (int i = 0; i < half; ++i) {
                mid_point = mid_point->next;
            }

            // reverse both list
            reverseList(head, size - half);
            reverseList(mid_point, size - half);

            // now do a pairwise swap
            for (int i = 0; i < size / 2 /* floor */; ++i) {
                int temp_val = head->val;
                head->val = mid_point->val;
                mid_point->val = temp_val;

                head = head->next;
                mid_point = mid_point->next;
            }
        }
    }
};

int main() {
    make_list_node(int, a, 1, 2, 3, 4, 5);
    make_list_node(int, b, 5);
    make_list_node(int, c, 1, 2, 3, 4);
    print_v(a0, b0, c0);
    print_v(*Solution().reverseBetween(&a0, 2, 4));
    print_v(*Solution().reverseBetween(&b0, 1, 1));
    print_v(*Solution().reverseBetween(&c0, 1, 4));
}
