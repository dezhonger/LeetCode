class Solution:
    def onesMinusZeros(self, grid: List[List[int]]) -> List[List[int]]:
        r = [0] * len(grid)
        c = [0] * len(grid[0])
        for i, row in enumerate(grid):
            for j, x in enumerate(row):
                r[i] += x * 2 - 1
                c[j] += x * 2 - 1  # 1 -> 1, 0 -> -1
        for i, x in enumerate(r):
            for j, y in enumerate(c):
                grid[i][j] = x + y
        return grid
