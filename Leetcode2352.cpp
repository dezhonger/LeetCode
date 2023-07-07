class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        map<vector<int>, int> cnt;
        for (auto row : grid) cnt[row]++;

        int res = 0;
        for (int j = 0; j < n; j++) {
            vector<int> arr;
            for (int i = 0; i < n; i++) arr.emplace_back(grid[i][j]);
            if (cnt.find(arr) != cnt.end()) res += cnt[arr];
        }
        return res;
    }
};
