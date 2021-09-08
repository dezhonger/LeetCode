const int N = 4000040;
int son[N][26], idx, cnt[N];

class StreamChecker {
public:
    string q;
    void insert(string& w) {
        int p = 0;
        for (int i = w.size() - 1; i >= 0; i--) {
            int u = w[i] - 'a';
            if (!son[p][u]) son[p][u] = ++idx;
            p = son[p][u];
        }
        cnt[p]++;
    }
    
    StreamChecker(vector<string>& words) {
        idx = 0;
        memset(son, 0, sizeof son);
        memset(cnt, 0, sizeof cnt);
        q.clear();
        for (auto& w: words) insert(w);
    }
    
    bool query(char letter) {
        int p = 0;
        q += letter;
        for (int i = q.size() - 1; i >= 0; i--) {
            int u = q[i] - 'a';
            if (!son[p][u]) return false;
            p = son[p][u];
            if (cnt[p]) return true;
        }
        return false;
    }
};
