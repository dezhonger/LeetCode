class Solution:
    def divideString(self, s: str, k: int, fill: str) -> List[str]:
        l = []
        if (len(s) % k != 0):
            s += fill * (k - len(s) % k)
        for i in range(0, len(s), k):
            l.append(s[i: i + k])
        return l
