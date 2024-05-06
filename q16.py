"""
16. 3Sum Closest

Given an array nums of n integers and an integer target,
find three integers in nums such that the sum is closest
to target. Return the sum of the three integers.

You may assume that each input would have exactly one solution.

https://leetcode.com/problems/3sum-closest/
"""
from typing import List


class Solution:
    """
    First sort the array,
    From smallest to largest, for each num, search in nums to the left,
    for the last two num.  Start from the item at i+1 and size-1 then:
    - record this difference to the sum if it is smaller than the currently recorded one
    - if the sum is too big, move the bigger pointer to the left
    - if the sum is too small, move the smaller pointer to the right
    """

    def threeSumClosest(self, nums: List[int], target: int) -> int:
        closest = None
        nums.sort()
        for i in range(len(nums)):
            left, right = i + 1, len(nums) - 1
            while left < right:
                s = nums[i] + nums[left] + nums[right]
                if closest is None or abs(target - s) < abs(target - closest):
                    closest = s
                if s > target:
                    right -= 1
                else:
                    left += 1
        return closest
