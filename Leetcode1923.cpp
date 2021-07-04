typedef unsigned long long ULL;
typedef long long LL;
int mod = (int)1e9 + 7;
const int N = 100010, P = 1333331;

ULL h[N], p[N];
//下标从1开始
ULL get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int m;

class Solution {
public:
    bool check(int mid, vector<vector<int>>& paths) {
        unordered_map<ULL, int> cnt, s;
        cnt.clear(), s.clear();
        for (int i = 0; i < m; i++) {
            auto str = paths[i];

            p[0] = 1;
            for (int j = 1; j <= str.size(); j++) {
                h[j] = h[j - 1] * P + str[j - 1];
                p[j] = p[j - 1] * P;
            }
            for (int j = mid; j <= str.size(); j++) {
                auto v = get(j - mid + 1, j);
                if (!s.count(v) || s[v] != i) {
                    // 如果第一次出现这个子串，或者在当前行第一次出现这个子串
                    cnt[v]++;
                    s[v] = i;
                }
            }
        }
        int res = 0;
        for (auto& [k, c]: cnt) res = max(res, c);
        return res == m;
    }

    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        m = paths.size();
        int l = 0, r = 0;
        for (int i = 0; i < m; i++) {
            r = max(r, (int)paths[i].size());
        }
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (check(mid, paths)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};
