class Solution:
    def minimumPartition(self, s: str, k: int) -> int:
        x = 0
        ans = 0
        for v in map(int, s):
            if v > k: return -1
            x = x * 10 + v
            if x > k:
                ans += 1
                x = v
        return ans + 1
