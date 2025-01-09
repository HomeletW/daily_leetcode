/**
 * 25. Reverse Nodes in k-Group
 * https://leetcode.com/problems/reverse-nodes-in-k-group
 *
 * Date: 2025-01-09
 */

#include "my_util.hpp"
#include "my_list_node.hpp"

using namespace std;

using ListNode = ListNode_generic<int>;

void print_k(ListNode *head, int size) {
    print(h1(), "\n");
    for (int i = 0; i < size; ++i) {
        if (head == nullptr) {
            break;
        }
        print_var_oneline(i, head, head->val, head->next);
        head = head->next;
    }
}

class Solution {
public:
    ListNode *reverseKGroup_old(ListNode *head, int k) {
        ListNode *curr = head;
        vector<ListNode *> stack;
        while (curr != nullptr) {
            stack.push_back(curr);
            if (stack.size() == k) {
                // reset and perform the swapping
                for (int i = 0; i < k / 2; ++i) {
                    int temp = stack[i]->val;
                    stack[i]->val = stack[k - 1 - i]->val;
                    stack[k - 1 - i]->val = temp;
                }
                stack.clear();
            }
            curr = curr->next;
        }
        return head;
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode dummyHead{-1, head};
        ListNode *group_prev = &dummyHead, *group_start = group_prev->next, *group_end = group_start;
        int count = 0;
        while (group_end != nullptr) {
//            print_k(dummyHead.next, 5);
            group_end = group_end->next;
            ++count;
            if (count >= k) {
                // a group has formed, now start reversing
                ListNode *curr = group_start, *end = group_end;
                for (int i = 0; i < k; ++i) {
                    ListNode *temp = curr->next;
                    curr->next = end;
                    end = curr;
                    curr = temp;
                }
                // in the end, link the prev pointer to curr
                group_prev->next = end;
                // update the group pointers
                group_prev = group_start;
                group_start = group_end;
                group_end = group_start;
                count = 0;
            }
        }
        return dummyHead.next;
    }
};

int main() {
    make_list_node(int, n, 1, 2, 3, 4, 5);
    make_list_node(int, k, 1, 2, 3, 4, 5);
    make_list_node(int, j, 1, 2);
    print_v(*Solution().reverseKGroup(&n0, 2));
    print_v(*Solution().reverseKGroup(&k0, 3));
    print_v(*Solution().reverseKGroup(&j0, 2));
}
