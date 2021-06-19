
class Solution {
public:
    vector<int> f, a, sz, cnt;
    
    int find(int x) {
        return x == f[x] ? x : f[x] = find(f[x]);
    }
    
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size(), res = -1;
        f = vector<int>(n, -1);
        //每组里1的个数
        sz = vector<int>(n, 0);
        cnt = vector<int>(n + 1);
        a = vector<int>(n, 0);
        cnt[0] = n;
        iota(f.begin(), f.end(), 0);
        for (int i = 0; i < n; i++) {
            int idx = arr[i] - 1;
            a[idx] = 1;
            sz[find(idx)]++;
            cnt[0]--;
            if (idx > 0 && a[idx - 1] == 1) {
                if (find(idx) != find(idx - 1)) {
                    int s = sz[find(idx - 1)];
                    sz[find(idx)] += s;
                    f[find(idx - 1)] = find(idx);
                    cnt[s]--;
                }
            }
              if (idx + 1 < n && a[idx + 1] == 1) {
                if (find(idx) != find(idx + 1)) {
                    int s = sz[find(idx + 1)];
                    sz[find(idx)] += s;
                    f[find(idx + 1)] = find(idx);
                    cnt[s]--;
                }
            }
            cnt[sz[find(idx)]]++;
            if (cnt[m] > 0) res = i + 1;
        }
        return res;
    }
};
