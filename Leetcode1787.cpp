const int N = (1 << 10) + 10;


int f[2][N];
int g[2];
class Solution {
public:
    int minChanges(vector<int>& a, int k) {
        int n = a.size();
        // f[i][mask] 前i组,且异或和为mask的最少修改次数
        int mask = (1 << 10);
        memset(f, 0x3f, sizeof f);
        f[0][0] = 0;
        g[0] = 0;
        for (int i = 1; i <= k; i++) {
            unordered_map<int, int> cnt;
            // 下标从0开始
            int c = 0;
            int idx = i & 1, last = idx ^ 1;
            g[idx] = INT_MAX;
            for (int j = i - 1; j < n; j += k) {
                cnt[a[j]]++;
                c++;
            }
            for (int j = 0; j < mask; j++) {
                f[idx][j] = g[last] + c;
                for (auto [x, y]: cnt) {
                    f[idx][j] = min(f[idx][j], f[last][j ^ x] + c - cnt[x]);
                }
                g[idx] = min(g[idx], f[idx][j]);
            }
            
            for (int j = 0; j < mask; j++) f[last][j] = f[idx][j];
        }
        return f[k & 1][0];
    }
};
