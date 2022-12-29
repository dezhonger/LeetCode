class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        limits = {c: s.count(c) - k for c in 'abc'}
        if any(x < 0 for x in limits.values()):
            return -1
        
        cnt = {c: 0 for c in 'abc'}

        # sliding window
        ans = 0
        left = 0
        for right, c in enumerate(s):
            cnt[c] += 1
            while cnt[c] > limits[c]:
                cnt[s[left]] -= 1
                left += 1
            ans = max(ans, right - left + 1)
        return len(s) - ans



sol = Solution()
result = sol.takeCharacters("aabaaaacaabc", 2)
print(result)
