class Solution:
    def countCollisions(self, s: str) -> int:
        s = s.lstrip('L')  # 前缀向左的车不会发生碰撞
        s = s.rstrip('R')  # 后缀向右的车不会发生碰撞
        return len(s) - s.count('S')  # 剩下非停止的车必然会碰撞
