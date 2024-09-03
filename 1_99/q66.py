"""
66. Plus One

You are given a large integer represented as an integer array digits, where each
digits[i] is the ith digit of the integer. The digits are ordered from most
significant to least significant in left-to-right order. The large integer does
not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

https://leetcode.com/problems/plus-one/
"""

from typing import List


class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        if len(digits) == 0:
            return [1]
        else:
            if digits[-1] != 9:
                digits[-1] += 1
                return digits
            else:
                return self.plusOne(digits[:-1]) + [0]
