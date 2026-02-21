class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        n, m = len(s), len(p)

        dp = [[False] * (m + 1) for _ in range(n + 1)]
        dp[n][m] = True

        for j in range(m - 1, -1, -1):
            if j + 1 < m and p[j + 1] == '*':
                dp[n][j] = dp[n][j + 2]

        for i in range(n - 1, -1, -1):
            for j in range(m - 1, -1, -1):
                first_ok = (p[j] == s[i] or p[j] == '.')
                
                if j + 1 < m and p[j + 1] == '*':
                    dp[i][j] = dp[i][j + 2] or (first_ok and dp[i + 1][j])
                else:
                    dp[i][j] = first_ok and dp[i + 1][j + 1]

        return dp[0][0]
