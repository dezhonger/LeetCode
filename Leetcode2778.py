class Solution:
    def sumOfSquares(self, nums: List[int]) -> int:
        return sum(x * x for i, x in enumerate(nums, 1)
                         if len(nums) % i == 0)
