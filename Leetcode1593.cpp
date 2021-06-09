typedef unsigned long long ULL;
class Solution {
public:
    
    int res;
    const int P = 131;
    ULL h[20], p[20];
    
    void init(string& s) {
        p[0] = 1;
        for (int i = 1; i <= s.size(); i++) {
            h[i] = h[i - 1] * P + s[i - 1];
            p[i] = p[i - 1] * P;
        }
    }
    
    ULL f(int l, int r) {
        l++; r++;
        return h[r] - h[l - 1] * p[r - l + 1];
    }
    
    int maxUniqueSplit(string s) {
        res = 0;
        init(s);
        //for (int i = 0; i <= s.size(); i++)  debug(i, h[i]);
        //for (int i = 0; i < s.size(); i++) for (int j = i; j < s.size(); j++) debug(i, j, f(i + 1, j + 1));
        set<ULL> st;
        dfs(s, 0, st);
        return res;
    }
    
    void dfs(string& s, int idx, set<ULL>& st) {
        if (idx == s.size()) {
            res = max(res, (int)st.size());
            return ;
        }
        
        for (int i = idx + 1; i <= s.size(); i++) {
            ULL hsh = f(idx, i - 1);
            bool ff = (st.find(hsh) != st.end());
            if (!ff) st.insert(hsh);
            dfs(s, i, st);
            if (!ff) st.erase(hsh);
       }
    }
    
};
