"""
29. Search Insert Position

Given a sorted array of distinct integers and a target value, return the
index if the target is found. If not, return the index where it would be
if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

https://leetcode.com/problems/search-insert-position/
"""

from typing import List


class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if len(nums) == 0:
            return 0
        else:
            mid = len(nums) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] > target:
                return self.searchInsert(nums[:mid], target)
            else:
                return mid + self.searchInsert(nums[mid + 1:], target) + 1


print(Solution().searchInsert([1, 3, 5, 6], 8))
