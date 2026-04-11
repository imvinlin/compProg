class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if k == 1: return nums
        n = len(nums)

        logs = [0]*(n+1)
        for i in range(2,n+1):
            logs[i] = logs[i//2] + 1
        
        st = [[0]*n for _ in range(logs[n]+1)]
        st[0] = nums[:]

        j = 1
        while (1 << j) <= n:
            le = 1 << j
            h = le >> 1
            lm = n-le+1
            
            for i in range(lm):
                st[j][i] = max(st[j-1][i],st[j-1][i+h])
            j += 1
        
        res = []
        for i in range(n-k+1):
            p = logs[k]
            res.append(max(st[p][i],st[p][i+k-(1 << p)]))
        return res

