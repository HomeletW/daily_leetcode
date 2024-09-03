"""
493. Reverse Pairs

Given an integer array nums, return the number of reverse pairs in the array.

A reverse pair is a pair (i, j) where 0 <= i < j < nums.length and
nums[i] > 2 * nums[j].

https://leetcode.com/problems/reverse-pairs/
"""
from typing import List


class Solution:
    def reversePairs(self, nums: List[int]) -> int:
        return self.sort_and_count(nums)[0]

    def sort_and_count(self, L):
        if len(L) == 1:
            return 0, L
        else:
            mid = len(L) // 2
            r_A, A = self.sort_and_count(L[:mid])
            r_B, B = self.sort_and_count(L[mid:])
            r_AB, L_prime = self.merge_and_count(A, B)
            return r_A + r_B + r_AB, L_prime

    def merge_and_count(self, A, B):
        """
        A and B are sorted
        """
        i, j = 0, 0
        r = 0
        L_prime = []
        while i < len(A) or j < len(B):
            if i >= len(A):
                L_prime.append(B[j])
                j += 1
            elif j >= len(B):
                L_prime.append(A[i])
                i += 1
            elif A[i] > B[j]:
                # count reverse pairs
                k = i
                while k < len(A) and A[k] > B[j] * 2:
                    r += 1
                    k += 1
                L_prime.append(B[j])
                j += 1
            else:
                L_prime.append(A[i])
                i += 1
        return r, L_prime


print(Solution().sort_and_count([2, 4, 3, 5, 1]))
