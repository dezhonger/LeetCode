int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}

const int N = 100010, M = N << 1, C = 50;
int h[N], e[M], ne[M], idx;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

class Solution {
public:
    vector<int> depth, ans;
    void dfs(int u, int fa, vector<vector<int>>& c, vector<int>& nums, int d) {
        int w = nums[u];
        depth[u] = d;
        int maxDepth = -1;
        for (int j = 1; j <= C; j++) {
            if (c[j].size() > 0 && gcd(j, w) == 1) {
                if (depth[c[j][c[j].size() - 1]] > maxDepth) {
                    maxDepth = depth[c[j][c[j].size() - 1]];
                    ans[u] = c[j][c[j].size() - 1];
                }
            }
        }
        c[w].push_back(u);
        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            if (j == fa) continue;
            dfs(j, u, c, nums, d + 1);
        }
        c[w].pop_back();
    }
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        depth = vector<int>(n, -1);
        ans = vector<int>(n, -1);
        idx = 0;
        memset(h, -1, sizeof h);
        for (auto& e: edges) {
            int x = e[0], y = e[1];
            add(x, y), add(y, x);
        }
        //每个权值对应的节点列表
        vector<vector<int>> c(C + 1, vector<int>());
        dfs(0, -1, c, nums, 1);
        return ans;
    }
};
