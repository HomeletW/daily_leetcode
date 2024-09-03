"""
22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of
well-formed parentheses.

https://leetcode.com/problems/generate-parentheses/
"""
from typing import List

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        """
        Notice there are only two possibility when placing parenthesis:
        - Placing (
        - Placing )
        We will keep track of the number of "(" placed as `left` and the number
        of ")" placed as `right`.
        The idea is to add "(" whenever we can (when left <= n), during the
        process, also add ")" whenever we have a matching "(" (when right < left).
        """
        result = []

        def recursive_call(buffer, left, right):
            if left == right and len(buffer) == 2 * n:
                result.append("".join(buffer))
                return

            if left <= n:
                buffer.append("(")
                recursive_call(buffer, left + 1, right)
                buffer.pop()

            if right < left:
                buffer.append(")")
                recursive_call(buffer, left, right + 1)
                buffer.pop()

        recursive_call([], 0, 0)
        return result





expected = ["(((())))","((()()))","((())())","((()))()","(()(()))","(()()())","(()())()","(())(())","(())()()","()((()))","()(()())","()(())()","()()(())","()()()()"]
actual = Solution().generateParenthesis(4)
print(sorted(actual))
print(sorted(expected))
