class Solution {
public:
    vector<int> res;
    unordered_set<int> st;
    int n;
    unordered_map<int, vector<int>> mp;
    void dfs(int idx, int val) {
        if (idx == n) return ;
        res[idx] = val;
        st.insert(val);
        for (int x: mp[val]) {
            if (!st.count(x)) {
                dfs(idx + 1, x);
            }
        }
        
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        mp.clear();
        unordered_map<int, int> cnt;
        for (auto e: adjacentPairs) {
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
            cnt[e[0]]++;
            cnt[e[1]]++;
        }
        
        int first;
        for (auto [k, v]: cnt) {
            if (v == 1) {
                first = k;
                break;
            }
        }
        n = adjacentPairs.size();
        n++;
        res = vector<int>(n);
        st.clear();
        dfs(0, first);
        return res;
        
    }
};
