int mod = (int)1e9 + 7;

int power(int a, int r){
    int res = 1;
    for(; r; r >>= 1, a = 1LL * a * a % mod)
        if(r & 1) res = 1LL * res * a % mod;
    return res;
}
int inv(int n){
    return power(n, mod - 2);
}
int C(int m, int n){
    int res = 1;
    for(int i = 0; i < n; i += 1) res = 1LL * res * (m - i) % mod;
    for(int i = 1; i <= n; i += 1) res = 1LL * res * inv(i) % mod;
    return res;
}

class Solution {
public:
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        vector<int> res;
        for(auto v : queries){
            int n = v[0], k = v[1], ans = 1;
            for(int i = 2, r; i * i <= k; i += 1)
                if(k % i == 0){
                    for(r = 0; k % i == 0; k /= i) r += 1;
                    ans = 1LL * ans * C(n + r - 1, r) % mod;
                }
            if(k > 1) ans = 1LL * ans * n % mod;
            res.push_back(ans);
        }
        return res;
    }
};
