"""
390. Elimination Game

You have a list arr of all integers in the range [1, n] sorted in a strictly
increasing order. Apply the following algorithm on arr:

- Starting from left to right, remove the first number and every other number
afterward until you reach the end of the list.
- Repeat the previous step again, but this time from right to left, remove the
rightmost number and every other number from the remaining numbers.
- Keep repeating the steps again, alternating left to right and right to left,
until a single number remains.

Given the integer n, return the last number that remains in arr.

https://leetcode.com/problems/elimination-game/
"""


class Solution:
    """
    Keeping the last element in the sequence
    """

    def lastRemaining(self, n: int) -> int:
        last_element = n
        # direction:
        # - True when left to right
        # - False when right to left
        direction = True
        size = n
        # the difference in the sequence of number
        difference = 1
        while size > 1:
            if direction:  # left to right
                if size & 0x1 == 1:  # if size is odd
                    # the last element is decreased by 1
                    last_element -= difference
            else:  # right to left
                # the last element always decrease by 1
                last_element -= difference
            direction = not direction  # flip the direction
            size //= 2
            difference *= 2
        return last_element
