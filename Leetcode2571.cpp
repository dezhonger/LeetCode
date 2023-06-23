class Solution {
public:
    int minOperations(int n) {
        int ans = 1;
        while (n & (n - 1)) { // n 不是 2 的幂次
            int lb = n & -n;
            if (n & (lb << 1)) n += lb; // 多个连续 1
            else n -= lb; // 单个 1
            ++ans;
        }
        return ans;
    }
};
