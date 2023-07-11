use init function:

lc2320.cpp
    const int MOD = 1e9 + 7, MX = 1e4 + 1;
    int f[MX] = {1, 2};
    int init = []() {
        for (int i = 2; i < MX; ++i)
            f[i] = (f[i - 1] + f[i - 2]) % MOD;
        return 0;
    }();
    
    class Solution {
    public:
        int countHousePlacements(int n) {
            return (long) f[n] * f[n] % MOD;
        }
    };



function:

    function<void(int)> dfs = [&](int x) {
        vis[x] = true;
        ++cnt;
        for (int y: g[x]) if (!vis[y]) dfs(y);
    };

lc2201:
https://leetcode.cn/problems/count-artifacts-that-can-be-extracted/solution/tong-ji-ke-yi-ti-qu-de-gong-jian-by-leet-uszp/
自定义set hash：

auto pair_hash = [&n, fn = hash<int>()](const pair<int, int>& o) -> size_t {
            return fn(o.first * n + o.second);
        };

        unordered_set<pair<int, int>, decltype(pair_hash)> valid(0, pair_hash);
        for (const auto& pos: dig) {
            int r = pos[0], c = pos[1];
            valid.emplace(r, c);
        }
