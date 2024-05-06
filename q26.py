"""
26. Remove Duplicates from Sorted Array

Given an integer array nums sorted in non-decreasing
order, remove the duplicates in-place such that each
unique element appears only once. The relative order
of the elements should be kept the same.

https://leetcode.com/problems/remove-dh9guplicates-from-sorted-array/
"""
from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        """
        Keeping a "pivotal" quantity to test to, if the value equals to the
        pivotal, we go to the next one, if the value does not equal to the
        pivotal quantity, the value within nums[pivotal_index+1: current_index]
        are unwanted, so we replace them with data after it, also decrementing
        size.
        """
        pivot_index = 0
        i = 1
        size = len(nums)
        while pivot_index < size and i < size:
            if nums[i] == nums[pivot_index]:
                i += 1
            else:
                # we don't want nums[pivot_index+1: i]
                j, k = pivot_index + 1, i
                if j != k:
                    while k < size:
                        nums[j] = nums[k]
                        j += 1
                        k += 1
                    size -= i - pivot_index - 1
                pivot_index += 1
                i = pivot_index + 1
        j, k = pivot_index + 1, i
        if j != k:
            while k < size:
                nums[j] = nums[k]
                j += 1
                k += 1
            size -= i - pivot_index - 1
        return size

    def removeDuplicates2(self, nums: List[int]) -> int:
        """
        Keep two pointer, j scans through the array, nums[0: i] would be the
        portion of the array to keep. As j goes, if it encounters something that
        is different than what's currently pointed by i, we will increment i and
        put the value there. This way we are only keeping one copy of everything.
        Finally returns the size of the portion, that is i + 1.
        """
        if len(nums) == 0:
            return 0
        i, j = 0, 1
        while j < len(nums):
            if nums[i] != nums[j]:
                i += 1
                nums[i] = nums[j]
            j += 1
        return i + 1


n = [1, 1, 1, 1, 1, 1, 2, 5, 10, 52, 52, 52, 52]
print(Solution().removeDuplicates2(n))
print(n)
