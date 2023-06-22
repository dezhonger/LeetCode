class Solution:
    def kthLargestLevelSum(self, root: Optional[TreeNode], k: int) -> int:
        q = [root]
        sum = []
        while q:
            tmp, s = q, 0
            q = []
            for node in tmp:
                s += node.val
                if node.left: q.append(node.left)
                if node.right: q.append(node.right)
            sum.append(s)
        sum.sort()  # 也可以用快速选择
        return -1 if len(sum) < k else sum[-k]
