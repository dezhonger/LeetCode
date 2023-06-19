class Solution {
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        typedef pair<int, int> pii;
        // mp 里存着某个坐标在有向图里的编号
        map<pii, int> mp;
        // 往图里添加一个坐标为 (x, y) 的点
        auto add = [&](int x, int y) {
            pii p = pii(x, y);
            if (mp.count(p)) return;
            int idx = mp.size();
            mp[p] = idx;
        };
        
        // 把起点和终点添加到图里
        add(start[0], start[1]);
        add(target[0], target[1]);
        // 把特殊路径的端点添加到图里
        for (auto &road : specialRoads) add(road[0], road[1]), add(road[2], road[3]);

        int n = mp.size();
        // 记录一下每个点的横坐标和纵坐标，方便建图
        int X[n], Y[n];
        for (auto it = mp.begin(); it != mp.end(); it++) {
            X[it->second] = it->first.first;
            Y[it->second] = it->first.second;
        }

        // 开始构建有向图
        vector<int> e[n];
        vector<long long> v[n];
        // 首先，任意两点之间都可以互相直接到达
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (i != j) {
            e[i].push_back(j);
            v[i].push_back(abs(X[i] - X[j]) + abs(Y[i] - Y[j]));
        }
        // 其次，图里还存在特殊路径
        for (auto &road : specialRoads) {
            int sn = mp[pii(road[0], road[1])];
            int fn = mp[pii(road[2], road[3])];
            e[sn].push_back(fn);
            v[sn].push_back(road[4]);
        }
        
        // dijkstra 求从 S 到 T 的最短路
        int S = mp[pii(start[0], start[1])], T = mp[pii(target[0], target[1])];
        long long dis[n];
        memset(dis, -1, sizeof(dis));
        typedef pair<long long, int> pli;
        priority_queue<pli> pq;
        pq.push(pli(0, S));
        while (!pq.empty()) {
            pli p = pq.top(); pq.pop();
            int sn = p.second;
            long long d = -p.first;
            if (dis[sn] >= 0) continue;
            dis[sn] = d;
            for (int i = 0; i < e[sn].size(); i++) {
                int fn = e[sn][i];
                if (dis[fn] >= 0) continue;
                pq.push(pli(-d - v[sn][i], fn));
            }
        }
        return dis[T];
    }
};
