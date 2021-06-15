class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int l = 0, r = m - 1;
        while (l < r) {
            int mid = l + r >> 1;
            int maxV = -1, row;
            for (int i = 0; i < n; i++) {
                if (mat[i][mid] > maxV) {
                    maxV = mat[i][mid];
                    row = i;
                }
            }
            
            int left = mid > 0 ? mat[row][mid - 1] : -1;
            int right = mid + 1 < m ? mat[row][mid + 1] : -1;
            if (left < maxV && right < maxV) return {row, mid};
            if (left > maxV) r = mid - 1;
            else l = mid + 1;
        }
        int maxV = -1, row;
        for (int i = 0; i < n; i++) {
            if (mat[i][r] > maxV) {
                maxV = mat[i][r];
                row = i;
            }
        }
        return {row, r};
    }
};
