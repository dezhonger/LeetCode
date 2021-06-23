class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = n - 2; j >= 0; j--) {
                if (matrix[j][i] == 1) matrix[j][i] += matrix[j + 1][i];
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            sort(matrix[i].begin(), matrix[i].end());
            for (int j = m - 1; j >= 0; j--) {
                res = max(res, matrix[i][j] * (m - j));
            }
        }
        return res;
    }
};
