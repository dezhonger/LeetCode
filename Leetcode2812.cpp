struct DSU {
    std::vector<int> f, siz;
    
    DSU() {}
    DSU(int n) {
        init(n);
    }
    
    void init(int n) {
        f.resize(n);
        std::iota(f.begin(), f.end(), 0);
        siz.assign(n, 1);
    }
    
    int find(int x) {
        while (x != f[x]) {
            x = f[x] = f[f[x]];
        }
        return x;
    }
    
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        siz[x] += siz[y];
        f[y] = x;
        return true;
    }
    
    int size(int x) {
        return siz[find(x)];
    }
};

class Solution {
public:
	static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int maximumSafenessFactor(vector<vector<int>>& g) {
        int n = g.size();
		vector<pair<int, int>> q;
		vector<vector<int>> dis(n, vector<int>(n, -1));
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
		{
			if (g[i][j]) q.emplace_back(i, j), dis[i][j] = 0;
		}
		
		vector<vector<pair<int, int>>> groups = {q};
        while (!q.empty()) { // 多源 BFS
            vector<pair<int, int>> nq;
            for (auto &[i, j]: q) {
                for (auto &d: dirs) {
                    int x = i + d[0], y = j + d[1];
                    if (0 <= x && x < n && 0 <= y && y < n && dis[x][y] < 0) {
                        nq.emplace_back(x, y);
                        dis[x][y] = groups.size();
                    }
                }
            }
            groups.push_back(nq); // 相同 dis 分组记录
            q = move(nq);
        }
		
		DSU dsu(n * n);
		for (int ans = (int)groups.size() - 2; ans >= 0; ans--)
		{
			for (auto &[i, j]: groups[ans]) {
                for (auto &d: dirs) {
                    int x = i + d[0], y = j + d[1];
                    if (0 <= x && x < n && 0 <= y && y < n && dis[x][y] >= dis[i][j]) dsu.merge(x * n + y, i * n + j);
                }
            }
            if (dsu.find(0) == dsu.find(n * n - 1)) return ans;
		}
		return 0;
    }
};
