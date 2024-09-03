"""
58. Length of Last Word

Given a string s consisting of some words separated by some
number of spaces, return the length of the last word in the
string.

A word is a maximal substring consisting of non-space
characters only.

https://leetcode.com/problems/length-of-last-word/
"""


class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        i = len(s) - 1
        acc = 0
        word_matched = False
        while i >= 0:
            if s[i] == " ":
                if word_matched:
                    break
            else:
                if not word_matched:
                    word_matched = True
                acc += 1
            i -= 1
        return acc


print(Solution().lengthOfLastWord("   fly me   to   the moon  "))