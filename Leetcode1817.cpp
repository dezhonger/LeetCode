class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> res(k);
        unordered_map<int, unordered_set<int>> cnt;
        for (auto lg: logs) {
            cnt[lg[0]].insert(lg[1]);
        }
        for (auto [k, v]: cnt) {
            res[v.size() - 1]++;
        }
        return res;
    }
};
