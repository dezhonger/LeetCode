class Solution {
public:
    //[["#",".","*","."],["#","#","*","."]]
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size();
        vector<vector<char>> res = vector<vector<char>>(m, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j >= 0; j--) {
                if (box[i][j] == '*') continue;
                int k = j, c = 0;
                //找到下一个障碍物的位置
                while (k >= 0 && box[i][k] != '*') {
                    if (box[i][k] == '#') c++;
                    k--;
                }
                for (int p = j, q = 0; p > k; p--, q++) {
                    if (q < c) box[i][p] = '#';
                    else box[i][p] = '.';
                }
                j = k + 1;
            }
            for (int j = 0; j < m; j++) {
                res[j][n - 1 - i] = box[i][j];
            }
        }
        return res;
    }
};
