class Solution:
    def firstCompleteIndex(self, arr: List[int], mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        pos = [0] * (m * n + 1)
        for i, row in enumerate(mat):
            for j, x in enumerate(row):
                pos[x] = (i, j)
        row_cnt = [0] * m
        col_cnt = [0] * n
        for i, x in enumerate(arr):
            r, c = pos[x]
            row_cnt[r] += 1
            col_cnt[c] += 1
            if row_cnt[r] == n or col_cnt[c] == m:
                return i
