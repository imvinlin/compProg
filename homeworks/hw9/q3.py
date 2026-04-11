class Solution:
    def matrixBlockSum(self, mat: List[List[int]], k: int) -> List[List[int]]:
        m,n = len(mat), len(mat[0])
        
        pref = [[0]*(n+1) for _ in range(m+1)]
        for i in range(m):
            for j in range(n):
                pref[i+1][j+1] = (mat[i][j]+pref[i][j+1]+pref[i+1][j]-pref[i][j])
        
        res = [[0]*n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                t,b,l,r = max(0,i-k), min(m-1,i+k), max(0,j-k), min(n-1,j+k)
                res[i][j] = (pref[b+1][r+1]+pref[t][l]-pref[t][r+1]-pref[b+1][l])
        return res
