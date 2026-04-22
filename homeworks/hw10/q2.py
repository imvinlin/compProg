class Solution:
    def longestPrefix(self, s: str) -> str:
        n = len(s)
        lp = [0] * n
        j = 0

        for i in range(1,n):
            while j > 0 and s[i] != s[j]:
                j = lp[j-1]
            
            if s[i] == s[j]:
                j += 1
                lp[i] = j
        return s[:lp[-1]]

