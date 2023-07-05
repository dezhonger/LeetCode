class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int N = 1000;
        const int mod = 1e9 + 7;
        // f[i]表示第i天新增加的知道秘密的人数
        vector<int> f(1010);
        f[1] = 1;
        
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + delay; j <= min(i + forget - 1, N); j++) f[j] = (f[j] + f[i]) % mod;
        }

        long long ans = 0;
        for (int i = n; i > n - forget; i--) ans = (ans + f[i]) % mod;
        return ans;
    }
};
