"""
21. Merge Two Sorted Lists

Merge two sorted linked lists and return it as a sorted list.
The list should be made by splicing together the nodes of the first two lists.

https://leetcode.com/problems/merge-two-sorted-lists/
"""


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy_head = ListNode(0, None)
        head = dummy_head
        while l1 is not None or l2 is not None:
            if l1 is None:
                # add l2
                head.next = l2
                l2 = l2.next
            elif l2 is None:
                # add l1
                head.next = l1
                l1 = l1.next
            elif l1.val < l2.val:
                # add l1
                head.next = l1
                l1 = l1.next
            else:
                # add l2
                head.next = l2
                l2 = l2.next
            head = head.next
        return dummy_head.next
