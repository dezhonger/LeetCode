class Solution:
    def digitSum(self, s: str, k: int) -> str:
        while len(s) > k:
            st = [s[i: i + k] for i in range(0, len(s), k)]
            s = ''
            for e in st:
                val = 0
                for x in e:
                    val += int(x)
                s += str(val)
        return s
