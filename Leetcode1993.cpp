
const int N = 2020;
int h[N], e[N], ne[N], idx;
int c[N], cnt;
vector<vector<int>> vv;
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

class LockingTree {
public:
    void dfs(int u, vector<int>& fa) {
        // 存储u的所有父节点
        for (int x: fa) vv[u].push_back(x);
        fa.push_back(u);
        for (int i = h[u]; ~i; i = ne[i]) {
            dfs(e[i], fa);
        }
        fa.pop_back();
        
    }

    LockingTree(vector<int>& parent) {
        idx = 0;
        memset(h, -1, sizeof h);
        memset(c, 0, sizeof c);
        for (int i = 1; i < parent.size(); i++) add(parent[i], i);
        vector<int> fa;
        vv = vector<vector<int>> (parent.size(), vector<int>());
        dfs(0, fa);
    }
    
    bool lock(int num, int user) {
        if (c[num] != 0) return false;
        c[num] = user;
        return true;
    }
    
    bool unlock(int num, int user) {
        if (c[num] != user) return false;
        c[num] = 0;
        return true;
    }
    
    void jiesuo(int x) {
        if (c[x] != 0) c[x] = 0, cnt++;
        for (int i = h[x]; ~i; i = ne[i]) {
            
            jiesuo(e[i]);
        }
    }
    
    bool upgrade(int num, int user) {
        if (c[num] != 0) return false;
        for (int x: vv[num]) {
            if (c[x] != 0) return false;
        }
        cnt = 0;
        jiesuo(num);
        if (!cnt) return false;
        c[num] = user;
        return true;
    }
};
