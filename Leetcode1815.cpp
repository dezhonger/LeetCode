class Solution {
public:
    vector<int> w, f;
    int sz;
    
    int solve(int mask, int r) {
        if (f[mask] != -1) return f[mask];
        
        int res = 0;
        // 以下是dp转移
        for (int i = 1; i < sz; i++) {
            // 第i位是0，也就是说fre[i] == 0
            if (mask % w[i + 1] / w[i] == 0) continue;
            
            // 第i位不是0，可以尝试去使用它转移
            int t = solve(mask - w[i], (r - i + sz) % sz);
            if (r == i) res = max(res, t + 1);
            else res = max(res, t);
        }
        return f[mask] = res;
    }
    
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        this -> sz = batchSize;
        // 记录每种余数有多少种
        vector<int> fre(batchSize);
        
        // 记录总和模batchSize是多少
        int r = 0;
        for (int x: groups) {
            fre[x % batchSize]++;
            r = (r + x) % batchSize;
        }
        
        // 将数组映射到一个数字，w表示每一位的权重
        w.resize(batchSize + 1);
        // w[0]没有用，忽略即可
        w[1] = 1;
        // 自定义的一种权重
        int mask = 0;
        for (int i = 2; i <= batchSize; i++) w[i] = w[i - 1] * (fre[i - 1] + 1);
        // 状态表示
        for (int i = 1; i < batchSize; i++) mask += fre[i] * w[i];
        
        // 记忆化搜索，全部置为-1
        f.resize(w[batchSize], -1);
        return solve(mask, r) + fre[0];
    }
};
