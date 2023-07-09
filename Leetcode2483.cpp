class Solution:
    def bestClosingTime(self, customers: str) -> int:
        ans = 0
        min_cost = cost = customers.count('Y')
        for i, c in enumerate(customers, 1):
            if c == 'N': cost += 1
            else:
                cost -= 1
                if cost < min_cost:
                    cost = min_cost
                    ans = i
        return ans
