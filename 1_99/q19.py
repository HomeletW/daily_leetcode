"""
19. Remove Nth Node From End of List

Given the head of a linked list, remove the nth node from the end
of the list and return its head.

https://leetcode.com/problems/remove-nth-node-from-end-of-list/
"""


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    """
    Maintain two pointer, separated by n. Once the first pointer
    reach the end, the second pointer will point to the ListNode
    we wish to delete.
    """

    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy_head = ListNode(0, next=head)
        first, second = dummy_head, dummy_head
        # we advance first by n
        for _ in range(n + 1):
            first = first.next
        # then advance both first and second until first reach tail
        while first is not None:
            first = first.next
            second = second.next
        # remove second.next
        node_rm = second.next
        second.next = node_rm.next
        node_rm.next = None
        return dummy_head.next
