#define ps push_back
const int N = 1 << 10;
bool f[55][N];
int d[1010];
int sum[N];


class Solution {
public:

    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        memset(d, 0, sizeof d);
        memset(sum, 0, sizeof sum);
        int m = quantity.size();
        for (int s = 0; s < (1 << m); s++) {
            for (int i = 0; i < m; i++) {
                if ((s >> i) & 1) sum[s] += quantity[i];
            }
        }
        
        
        for (int x : nums) d[x]++;
        vector<int> v;
        for (int i = 1; i <= 1000; i++) {
            if (d[i]) v.ps(d[i]);
        }
        
        //f: 前i个数字满足的状态为s是否可以
        int n = v.size();
        memset(f, 0, sizeof f);
        for (int i = 0; i <= n;i ++) f[i][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int s = 0; s < (1 << m); s++) {
                f[i][s] |= f[i - 1][s];
                for (int sub = s; sub; sub = (sub - 1) & s) {
                    f[i][s] |= (f[i - 1][s ^ sub] & sum[sub] <= v[i - 1]);
                    if (f[i][s]) break;
                }
            }
        }
        return f[n][(1 << m) - 1];
        
    }
};
