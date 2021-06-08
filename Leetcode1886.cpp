class Solution {
public:

    int n;
    vector<vector<int>> rotate(vector<vector<int>> mat) {
        vector<vector<int>> res = mat;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = mat[n - j - 1][i];
            }
        }
        return res;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        n = mat.size();
        for (int i = 0; i < 4; i++) {
            mat = rotate(mat);
            if (mat == target) return true;
        }
        return false;
    }
};
