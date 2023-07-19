class Solution:
    def maximumNumberOfStringPairs(self, words: List[str]) -> int:
        ans, vis = 0, set()
        for s in words:
            if s[::-1] in vis:
                ans += 1
            else:
                vis.add(s)
        return ans
