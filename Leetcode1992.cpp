class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size(), m = land[0].size();
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (land[i][j] == 1 && (i == 0 || land[i - 1][j] != 1) && (j == 0 || land[i][j - 1] != 1)) {
                    int ii = i, jj = j;
                    while (ii < n && land[ii][j] == 1) ii++;
                    while (jj < m && land[i][jj] == 1) jj++;
                    res.push_back({i, j, ii - 1, jj - 1});
                }
            }
        }
        return res;
    }
};
