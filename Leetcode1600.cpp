const int N = 100010, M = N << 1;
int h[N], e[M], ne[M], idx;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

class ThroneInheritance {
public:
    unordered_map<string, int> mp;
    unordered_map<int, string> mp2;
    int c;
    vector<string> vs;
    int v[N];
    ThroneInheritance(string kingName) {
        c = 0;
        mp[kingName] = c;
        mp2[c++] = kingName;
        memset(v, 0, sizeof v);
        idx = 0;
        memset(h, -1, sizeof h);
        
    }
    
    void birth(string parentName, string childName) {
        mp[childName] = c;
        mp2[c++] = childName;
        int u = mp[parentName];
        int v = mp[childName];
        add(u, v);
    }
    
    void death(string name) {
        v[mp[name]] = 1;
    }
    
    void dfs(int u, int fa) {
        if (!v[u]) vs.emplace_back(mp2[u]);
        vector<int> ch;
        for (int i = h[u]; ~i; i = ne[i]) {
            int j = e[i];
            ch.emplace_back(j);
        }
        sort(ch.begin(), ch.end());
        for (int i = 0; i < ch.size(); i++) dfs(ch[i], u);
    }

    vector<string> getInheritanceOrder() {
        vs.clear();
        dfs(0, -1);
        return vs;
    }
};
