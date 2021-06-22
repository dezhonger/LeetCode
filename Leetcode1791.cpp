class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> mp;
        for (auto e: edges) {
            mp[e[0]] += 2, mp[e[1]] += 2;
            if (mp[e[0]] > 2) return e[0];
            if (mp[e[1]] > 2) return e[1];
        }
        return -1;
    }
};
