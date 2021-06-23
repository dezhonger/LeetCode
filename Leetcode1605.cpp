class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size(), m = colSum.size();
        vector<vector<int>> res(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int v = min(rowSum[i], colSum[j]);
                res[i][j] = v;
                rowSum[i] -= v;
                colSum[j] -= v;
            }
        }
        return res;
    }
};
