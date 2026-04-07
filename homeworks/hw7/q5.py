class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        m,n = len(grid), len(grid[0])
        visit = set()
        islands = 0

        def dfs(row,col):
            visit.add((row,col))
            for dr,dc in [(1,0),(-1,0),(0,1),(0,-1)]:
                r,c = row + dr, col + dc
                if 0 <= r < m and 0 <= c < n and (r,c) not in visit and grid[r][c] == "1":
                    dfs(r,c)

        for row in range(m):
            for col in range(n):
                if (row,col) not in visit and grid[row][col] == "1":
                    dfs(row,col)
                    islands += 1
        return islands
