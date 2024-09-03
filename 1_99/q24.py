"""
24. Swap Nodes in Pairs

Given a linked list, swap every two adjacent nodes and return its head.
You must solve the problem without modifying the values in the list's nodes
(i.e., only nodes themselves may be changed.)

https://leetcode.com/problems/swap-nodes-in-pairs/
"""
from typing import List


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if head is None:
            return None
        dummy_head = ListNode(next=head)
        current = dummy_head
        # swap the next two nodes
        while current.next is not None and current.next.next is not None:
            first = current.next
            second = current.next.next
            first.next = second.next
            second.next = first
            current.next = second
            # move to place after
            current = current.next.next
        return dummy_head.next


def test(arr):
    dummy_head = ListNode(next=None)
    curr = dummy_head
    for i in arr:
        curr.next = ListNode(val=i)
        curr = curr.next
    n_head = Solution().swapPairs(dummy_head.next)
    print(arr)
    result = []
    while n_head is not None:
        result.append(n_head.val)
        n_head = n_head.next
    print(result)


test([1, 2, 3, 4])
