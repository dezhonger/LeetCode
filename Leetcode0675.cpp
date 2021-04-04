struct A {
    int x, y, s;
};
class Solution {
public:
    int res = 0;
    vector<int> v;
    int n, m;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    A bfs(int x, int y, int t, vector<vector<int>>& f) {
        queue<A> q;
        vector<vector<bool>> visit(n, vector<bool>(m, false));
        q.push({x, y, 0});
        visit[x][y] = 1;
        while(!q.empty()) {
            A a = q.front();
            q.pop();
            
           
            if (f[a.x][a.y] == t) return a;
            for (int i = 0; i < 4; i++) {
                int _x = a.x + dx[i], _y = a.y + dy[i];

                if (_x >= 0 && _y >= 0 && _x < n && _y < m && f[_x][_y] != 0 && !visit[_x][_y]) {
                    q.push({_x, _y, a.s + 1});
                    visit[_x][_y] = true;
                }
            }
        }
        return {-1, -1, -1};
    }

    
    int cutOffTree(vector<vector<int>>& forest) {
        n = forest.size(), m = forest[0].size();
        v.clear();
        res = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (forest[i][j] != 0) v.push_back(forest[i][j]);
        sort(v.begin(), v.end());
        int x = 0, y = 0;
        for (int i = 0; i < v.size(); i++) {
            A r = bfs(x, y, v[i], forest);
            if (r.s == -1) {
                return -1;
            }
            res += r.s;
            x = r.x, y = r.y;
        }
        
        return res;
        
    }
};
