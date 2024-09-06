class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        start, end = m-1, n-1
        memo = [[-1 for _ in range(n)] for _ in range(m)]

        def helper(i, j):
            if i<0 or j<0:
                return 0

            if memo[i][j] != -1:
                return memo[i][j]

            if i == 0 and j == 0:
                return 1

            left = helper(i, j-1)
            up = helper(i-1, j)

            memo[i][j] = left + up
            return memo[i][j]

        return helper(start, end)
    