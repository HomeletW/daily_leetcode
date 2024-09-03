/**
 * 141. Linked List Cycle
 * https://leetcode.com/problems/linked-list-cycle
 */

#include "my_util.hpp"
#include "my_list_node.hpp"

using namespace std;

using ListNode = ListNode_generic<int>;

class Solution {
public:
    bool hasCycle_old(ListNode *head) {
        unordered_set<ListNode *> hashset;
        while (head != nullptr) {
            if (hashset.contains(head)) {
                return true;
            } else {
                hashset.insert(head);
                head = head->next;
            }
        }
        return false;
    }

    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }
        // idea is use a slow and fast pointer
        // if there is a cycle, they will eventually meet
        ListNode *slow = head;
        ListNode *fast = head;
        while (slow->next != nullptr && fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    make_list_node(int, a, 3, 0, 2, 4);
    a3.next = &a1;
    make_list_node(int, b, 1, 2);
    b1.next = &b0;
    make_list_node(int, c, 1);
    make_list_node(int, d, 1, 2, 3, 4, 1, 5, 3, 2);
    print_v(Solution().hasCycle(&a0));
    print_v(Solution().hasCycle(&b0));
    print_v(Solution().hasCycle(&c0));
    print_v(Solution().hasCycle(&d0));
    print_v(Solution().hasCycle(nullptr));
}
