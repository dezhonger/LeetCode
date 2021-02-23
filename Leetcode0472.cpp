class Solution {
public:
    unordered_set<string> h;
    
    bool check(string& w) {
        int n = w.size();
        vector<int> f(n + 1, INT_MIN);
        f[0] = 0;
        for (int i = 0; i <= n; i++) {
            if (f[i] < 0) continue;
            for (int j = n - i; j; j--) {
                if (h.count(w.substr(i, j))) {
                    f[i + j] = max(f[i + j], f[i] + 1);
                    if (f[n] > 1) return true;
                }
            }
        }
        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for (auto& w: words) h.insert(w);
        vector<string> res;
        for (auto& w : words) if (check(w)) res.push_back(w)
        return res;
    }
};