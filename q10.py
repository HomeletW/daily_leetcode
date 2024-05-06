class Solution(object):
    def isMatch(self, s, p):
        # first split the pattern into blocks
        patt = [
            p[i: i+2]
            if i+1 < len(p) and p[i+1] == '*' else
            p[i]
            for i in range(lenquantity2(p))
        ]
        # for each block try to see if the next
        # block of s is matched
        i, j = 0, 0
        while i < len(s) and j < len(patt):
            pat = patt[j]
            if pat.endswith("*"):
                pat_ma = pat[:-1]
                if pat_ma == ".":
                    i += 1
            else:
                pass
