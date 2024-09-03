"""
18. 4Sum

Given an array nums of n integers, return an array of all
the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

- 0 <= a, b, c, d < n
- a, b, c, and d are distinct.
- nums[a] + nums[b] + nums[c] + nums[d] == target

You may return the answer in any order.

https://leetcode.com/problems/4sum/
"""
from typing import List


class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        """
        Make a dictionary that maps the sum of all combination of two numbers
        """
        pass

    def fourSum1(self, nums: List[int], target: int) -> List[List[int]]:
        """
        We can use the recursive approach:
        Notice from k sum to k-1 sum, we need to deduct the target by each
        choice of num and remove that choice from num (use a bit vector
        to keep track of which number is used). We terminate the recursion
        at k=1, return all num remains at nums and equals to left over target.
        During backtrack, we build the result array.

        To tackle the uniqueness constrain, we can only return it's index in
        num and sort each tuple, in the end, we can iterate through them to
        remove the duplicates. We can apply a function
            f(x1 ... xn) = p1^x1 + p2^x2 + ...
        to check uniqueness, where p1...p2 are prime.

        Notice this will not change the asymptotic complexity, since the
        results are certainly less than all possible combination.
        """
        # sort nums
        nums.sort()

        def kSum(k: int, bv: int, t: int) -> List[List[int]]:
            if k == 1:
                result = []
                for i in range(len(nums)):
                    if not bv & (1 << i) and nums[i] == t:
                        result.append([nums[i]])
                return result
            else:
                # optimization, we can stop if:
                # - the smallest item * k is greater than target
                # - the largest item * k is smaller than target
                result = []
                # find the first item
                for i in range(len(nums)):
                    if not bv & (1 << i):
                        if nums[i] * k > target:
                            return result
                        else:
                            break
                # find the last item
                # for i in range(len(nums) - 1, -1, -1):
                #     if not bv & (1 << i):
                #         if nums[i] * k < target:
                #             return result
                #         else:
                #             break
                # for each available choice
                for i in range(len(nums)):
                    if not bv & (1 << i):
                        for res in kSum(k - 1, bv | (1 << i), t - nums[i]):
                            result.append(res + [nums[i]])
                return result

        def h(t) -> int:
            return sum(p ** g(x) for x, p in zip(t, [2, 3, 5, 7]))

        def g(x) -> int:
            if x < 0:
                return -2 * x
            else:
                return 2 * x + 1

        s = set()
        keep = []
        for r in kSum(4, 0b0, target):
            a = h(sorted(r))
            if a not in s:
                s.add(a)
                keep.append(sorted(r))
        return sorted(keep)


# print(Solution().fourSum([1, 0, -1, 0, -2, 2], 0))
# print(Solution().fourSum([2, 2, 2, 2, 2], 8))
# print(Solution().fourSum([-5, -4, -3, -2, -1, 0, 0, 1, 2, 3, 4, 5], 0))
# print("====== expected")
# expt = [[-5, -4, 4, 5], [-5, -3, 3, 5], [-5, -2, 2, 5], [-5, -2, 3, 4],
#         [-5, -1, 1, 5], [-5, -1, 2, 4], [-5, 0, 0, 5], [-5, 0, 1, 4],
#         [-5, 0, 2, 3], [-4, -3, 2, 5], [-4, -3, 3, 4], [-4, -2, 1, 5],
#         [-4, -2, 2, 4], [-4, -1, 0, 5], [-4, -1, 1, 4], [-4, -1, 2, 3],
#         [-4, 0, 0, 4], [-4, 0, 1, 3], [-3, -2, 0, 5], [-3, -2, 1, 4],
#         [-3, -2, 2, 3], [-3, -1, 0, 4], [-3, -1, 1, 3], [-3, 0, 0, 3],
#         [-3, 0, 1, 2], [-2, -1, 0, 3], [-2, -1, 1, 2], [-2, 0, 0, 2],
#         [-1, 0, 0, 1]]
# print(sorted(expt))
nums = [-497, -494, -484, -477, -453, -453, -444, -442, -428, -420, -401, -393,
        -392, -381, -357, -357, -327, -323, -306, -285, -284, -263, -262, -254,
        -243, -234, -208, -170, -166, -162, -158, -136, -133, -130, -119, -114,
        -101, -100, -86, -66, -65, -6, 1, 3, 4, 11, 69, 77, 78, 107, 108, 108,
        121, 123, 136, 137, 151, 153, 155, 166, 170, 175, 179, 211, 230, 251,
        255, 266, 288, 306, 308, 310, 314, 321, 322, 331, 333, 334, 347, 349,
        356, 357, 360, 361, 361, 367, 375, 378, 387, 387, 408, 414, 421, 435,
        439, 440, 441, 470, 492]
target = 1682

print(Solution().fourSum(nums, target))
