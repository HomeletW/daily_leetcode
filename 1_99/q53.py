"""
53. Maximum Subarray

Given an integer array nums, find the contiguous subarray
(containing at least one number) which has the largest sum
and return its sum.

A subarray is a contiguous part of an array.

https://leetcode.com/problems/maximum-subarray/
"""

from typing import List


class Solution:
    """
    Iterate through the array, keeping track of two values:

    - Global maximum
    - The maximum of the last contiguous part of the array
    """

    def maxSubArray(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        global_max = nums[0]
        last_contiguous = nums[0]
        i = 1
        while i < len(nums):
            # decide to drop the contiguous or not
            # - if the current value is greater than the sum of the last subarray, then we can drop it.
            last_contiguous = max(nums[i], nums[i] + last_contiguous)
            global_max = max(last_contiguous, global_max)
            i += 1
        return global_max
