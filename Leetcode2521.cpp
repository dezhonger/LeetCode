class Solution:
    def distinctPrimeFactors(self, nums: List[int]) -> int:
        s = set()
        for x in nums:
            i = 2
            while i * i <= x:
                if x % i == 0:
                    s.add(i)
                    x //= i
                    while x % i == 0:
                        x //= i
                i += 1
            if x > 1:
                s.add(x)
        return len(s)
