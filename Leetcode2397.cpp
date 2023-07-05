class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> mask(m);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                mask[i] += (matrix[i][j] << j);
        
        //  Gosper's Hack algorithm
        int set = (1 << numSelect) - 1, ans = 0;
        while (set < 1 << n)
        {
            int sum = 0;
            // row & set = row 表示 row 是 set 的子集， 所有 1 都被覆盖
            for (int row : mask) sum += ((row & set) == row);
            ans = max(ans, sum);

            int lb = set & -set;
            int x = set + lb;
            // set = (((x ^ set) >> 2) / lb) | x;
            set = ((set ^ x) >> ( __builtin_ctz(lb) + 2)) | x;
        }
        return ans;
    }
};
