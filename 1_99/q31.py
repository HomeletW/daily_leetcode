"""
31. Next Permutation

Implement next permutation, which rearranges numbers into the lexicographically
next greater permutation of numbers.

If such an arrangement is not possible, it must rearrange it as the lowest
possible order (i.e., sorted in ascending order).

The replacement must be in place and use only constant extra memory.

https://leetcode.com/problems/next-permutation/
"""
from typing import List

class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Since we want the next lexicographically greater number, as we iterate
        from backwards, as soon as we encounter a decreasing number, we now need
        to swap it with a number that is just bigger than the current number.
        Notice all the number that we just iterated are all increasing order.

        After this, we get an lexicographically greater number, but it's still
        not the smallest, we need to arrange the number we just iterated in
        increasing order (because we are iterating backwards, we need to reverse
        them).

        Do not return anything, modify nums in-place instead.
        """
        i = len(nums) - 2
        while i >= 0:
            if nums[i] < nums[i + 1]:
                # the first decreasing number is i
                j = i + 1
                while j < len(nums):
                    if nums[j] <= nums[i]:
                        break
                    j += 1
                # swap j-1 and i
                nums[i], nums[j - 1] = nums[j - 1], nums[i]
                break
            i -= 1
        # reverse the array nums[i + 1:]
        j, k = i + 1, len(nums) - 1
        while j < k:
            nums[j], nums[k] = nums[k], nums[j]
            j += 1
            k -= 1


def test(arr):
    Solution().nextPermutation(arr)
    print(arr)


test([1, 1, 5])
test([1, 2, 3])
test([3, 2, 1])
