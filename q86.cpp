/**
 * 86. Partition List
 * https://leetcode.com/problems/partition-list
 *
 * Date: 2025-01-14
 */

#include "my_util.hpp"
#include "my_list_node.hpp"

using ListNode = ListNode_generic<int>;

using namespace std;

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (head == nullptr) {
            return nullptr;  // length 0
        } else if (head->next == nullptr) {
            return head;     // length 1
        }
        ListNode dummyHead{-1, head};
        // part1_node should be the end of the part1, such that part1_node->next should be the start of part2
        // part2_node should be the end of the part2, such that part2_node->next should be the next unprocessed node
        // (and eventually equals to nullptr)
        ListNode *part1_node = &dummyHead, *part2_node = &dummyHead;
        while (part2_node->next != nullptr) {
            ListNode *next = part2_node->next;
            if (next->val < x) {
                print_var_oneline(next->val, "part1");
                // should be appended to part1
                if (part1_node == part2_node) {
                    // special case when part1 is empty
                    part1_node = part1_node->next;
                    part2_node = part2_node->next;
                } else {
                    part2_node->next = next->next;
                    next->next = part1_node->next;
                    part1_node->next = next;
                    part1_node = next;
                }
            } else {
                print_var_oneline(next->val, "part2");
                // should be appended to part2
                // just move back the part2_node pointer
                part2_node = part2_node->next;
            }
            print_v(*part1_node, *part2_node);
            print_line(h1());
        }
        return dummyHead.next;
    }
};

int main() {
    make_list_node(int, a, 1, 4, 3, 2, 5, 2);
    make_list_node(int, b, 2, 1);
    make_list_node(int, c, 6, 1, 2, 3, 4, 5);
    print_v(a0, b0, c0);
    print_v(*Solution().partition(&a0, 3));
    print_v(*Solution().partition(&b0, 2));
    print_v(*Solution().partition(&c0, 3));
}
