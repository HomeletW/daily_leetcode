"""
28. Implement strStr()

Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if
needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question
to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty
string. This is consistent to C's strstr() and Java's indexOf().

https://leetcode.com/problems/implement-strstr/
"""


class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if len(needle) == 0:
            return 0
        i = 0
        while i < len(haystack):
            j = 0
            notMatched = False
            while j < len(needle):
                if i + j >= len(haystack):
                    return -1
                if haystack[i + j] != needle[j]:
                    notMatched = True
                j += 1
            if not notMatched:
                return i
            i += 1
        return -1


print(Solution().strStr("1234", "23"))
