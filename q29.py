"""
29. Divide Two Integers

Given two integers dividend and divisor, divide two integers without using
multiplication, division, and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero, which means losing its
fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.

Note: Assume we are dealing with an environment that could only store integers
within the 32-bit signed integer range: [−231, 231 − 1]. For this problem,
assume that your function returns 231 − 1 when the division result overflows.

https://leetcode.com/problems/divide-two-integers/
"""


class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        """
        TODO: Runtime exceed !!!!
        """
        divd = abs(dividend)
        divs = abs(divisor)
        count = 0
        while divd >= divs:
            divd -= divs
            count += 1
        if ((dividend >> 31) ^ (divisor >> 31)) != 0:  # XOR
            # if they have different sign
            return -count
        else:
            return count
