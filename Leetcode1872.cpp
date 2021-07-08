class Solution {
public:
    // 暴力解法
    int stoneGameVIII_brute_force(vector<int>& a) {
        int n = a.size();
        vector<int> f(n + 2), s(n + 1);
        // f[i] 表示可以从[i, i+1, ..., n]拿石子的时候，alice和bob的最大差值
        // 如果拿i的话，得分为1-i的和，下一个人可以拿的范围就是[i+1到n], 即为f[i+1]
        
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i - 1];
        //直接拿最后一个的话，得分就是全部石子的和
        f[n] = s[n];
        for (int i = n - 1; i >= 2; i--) {
            //f[i]:从[i, n]的最大值，因此先赋值f[i+1, i+2, ...n]的最大值
            f[i] = f[i + 1];
            for (int j = i; j <= n; j++) {
                //当前人拿的范围是[i, n]
                f[i] = max(f[i], s[j] - f[j + 1]);
            }
        }
        //第一个石子是不能拿的
        return f[2];
    }
    
    int stoneGameVIII(vector<int>& a) {
        int n = a.size();
        vector<int> f(n + 2), s(n + 1);
        //对暴力算法进行优化
        
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i - 1];
        f[n] = s[n];
        int maxV = max(s[n - 1] - f[n], s[n]);
        for (int i = n - 1; i >= 2; i--) {
            f[i] = max(f[i + 1], maxV);
            maxV = max(maxV, s[i - 1] - f[i]);
        }
        //第一个石子是不能拿的
        return f[2];
    }
};
