class Solution:
    def maxDivScore(self, nums: List[int], divisors: List[int]) -> int:
        max_cnt = -1
        ans = 0
        for d in divisors:
            cnt = sum(x % d == 0 for x in nums)
            if cnt > max_cnt or cnt == max_cnt and d < ans:
                max_cnt = cnt
                ans = d
        return ans
