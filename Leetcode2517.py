class Solution:
    def maximumTastiness(self, price: list[int], k: int) -> int:
        def check(x):
            last, count, i = price[0], 1, 1
            while count < k and i < len(price):
                if price[i] - last >= x:
                    last = price[i]
                    count += 1
                i += 1
            return count == k
        
        price.sort()
        l, r = 0, 10 ** 9
        while l < r:
            mid = (l + r + 1) // 2
            if (check(mid)): l = mid
            else: r = mid - 1
        return l

sol = Solution()
result = sol.maximumTastiness([13,5,1,8,21,2],3)
print(result)
