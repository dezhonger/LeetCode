class Solution:
    def findLonely(self, nums: List[int]) -> List[int]:
        res = []
        freq = Counter(nums)   # 每个元素出现次数哈希表
        for num in nums:
            if freq[num - 1] == 0 and freq[num + 1] == 0 and freq[num] == 1:
                res.append(num)
        return res
