const int N = 105;
int f[N][N];
class Solution {
public:
    int v, n, m;
    vector<vector<int>> h;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    bool dfs(int x, int y, int val) {
        if (x == n - 1 && y == m - 1) return true;
        bool res = false;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && f[nx][ny] == -1 && abs(val - h[nx][ny]) <= v) {
                f[nx][ny] = 0;
                res |= dfs(nx, ny, h[nx][ny]);
                if (res) return res;
                //f[nx][ny] = -1;
            }
        }
        return res;
    }

    bool check(int _v, vector<vector<int>>& h) {
        v = _v;
        memset(f, -1, sizeof f);
        f[0][0] = 0;
        return dfs(0, 0, h[0][0]);
    }

    int minimumEffortPath(vector<vector<int>>& _h) {
        h = _h;
        n = h.size(), m = h[0].size();
        int minV = INT_MAX, maxV = INT_MIN;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                minV = min(minV, h[i][j]);
                maxV = max(maxV, h[i][j]);
            }
        }
        int l = 0, r = 1000010;
        while (l < r) {
            int mid = l + r >> 1;
            if (check(mid, h)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
