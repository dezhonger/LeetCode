class Solution:
    def makeIntegerBeautiful(self, n: int, target: int) -> int:
        tail = 1
        while True:
            m = x = n + (tail - n % tail) % tail  # 进位后的数字
            s = 0
            while x:
                s += x % 10
                x //= 10
            if s <= target: return m - n
            tail *= 10
