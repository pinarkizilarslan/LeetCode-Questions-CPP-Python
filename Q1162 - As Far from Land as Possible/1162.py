class Solution:
    def maxDistance(self, grid: List[List[int]]) -> int:

        row = len(grid)
        q = []
        dp = [[-1 for _ in range(row)] for _ in range(row)]

        def isvalid(i,j):
            if (0<=i<row and 0<=j<row and grid[i][j]==0):
                return True
            return False

        for i in range(row):
            for j in range(row):
                if (grid[i][j]==1):
                    q.append((i,j))
                    dp[i][j]=0

        res = -1
        while q:
            x,y = q.pop(0)
            for dx,dy in [(1,0),(-1,0),(0,-1),(0,1)]:
                if (isvalid(x+dx,y+dy) and dp[x+dx][y+dy]==-1):
                    q.append((x+dx,y+dy))
                    dp[x+dx][y+dy] = dp[x][y]+1
                    res = max(res,dp[x+dx][y+dy])

        return res