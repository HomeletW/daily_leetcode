"""
17. Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive,
return all possible letter combinations that the number
could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone
buttons) is given below.

Note that 1 does not map to any letters.

1       2(abc) 3(def)
4(ghi)  5(jkl) 6(mno)
7(pqrs) 8(tuv) 9(wxyz)
*       0      #

https://leetcode.com/problems/letter-combinations-of-a-phone-number/
"""
from typing import List


class Solution:
    """
    Using BFS / DFS, iterate through all possible combination
    """

    def letterCombinations(self, digits: str) -> List[str]:
        dl_map = {"2": "abc", "3": "def",
                  "4": "ghi", "5": "jkl", "6": "mno",
                  "7": "pqrs", "8": "tuv", "9": "wxyz"}

        def dfs_visit(buffer: str, i: int) -> list:
            if i >= len(digits):
                return [buffer]
            else:
                res = []
                for letter in dl_map[digits[i]]:
                    res.extend(dfs_visit(buffer + letter, i + 1))
                return res

        if len(digits) == 0:
            return []
        return dfs_visit("", 0)


print(Solution().letterCombinations("23"))
