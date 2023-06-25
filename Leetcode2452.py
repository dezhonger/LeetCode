class Solution:
    def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:
        ans = []
        for q in queries:
            for s in dictionary:
                if sum(x != y for x, y in zip(q, s)) <= 2:
                    ans.append(q)
                    break
        return ans
