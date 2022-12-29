class Solution:
    def closetTarget(self, words: list[str], target: str, startIndex: int) -> int:
        if target not in words:
            return -1
        
        n = len(words)

        for i in range(n):
            if (words[(startIndex + i) % n]) == target:
                break

        for j in range(n):
            if (words[(startIndex - j + n) % n]) == target:
                break    
        
        return min(i, j)

s = Solution()
result = s.closetTarget(["hello","i","am","leetcode","hello"], "hello", 1)
print(result)

