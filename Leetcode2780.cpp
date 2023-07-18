class Solution:
    def minimumIndex(self, nums: List[int]) -> int:
        mode, total = Counter(nums).most_common(1)[0]
        freq1 = 0
        for i, x in enumerate(nums):
            freq1 += x == mode
            if freq1 * 2 > i + 1 and (total - freq1) * 2 > len(nums) - i - 1:
                return i
        return -1
