class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& g) {
        //n: 行数 m:列数
        int n = g.size(), m = g[0].size();

        vector<vector<int>> res(n, vector<int>(m, 0));

        // 编号对角线 [1, n + m - 1]
        for (int s = 1; s <= n + m - 1; s++)
        {
            // 对角线起始纵坐标
            int minJ = max(0, m - s);
            // 对角线结束纵坐标
            int maxJ = min(m - 1, n + m - 1 - s);

            unordered_set<int> st;
            for (int j = minJ; j < maxJ; j++)
            {
                // 对应的横坐标
                int i = s + j - m;
                st.insert(g[i][j]);
                res[i + 1][j + 1] = st.size();
            }

            st.clear();
            for (int j = maxJ; j > minJ; j--)
            {
                // 对应的横坐标
                int i = s + j - m;
                st.insert(g[i][j]);
                res[i - 1][j - 1] = abs(res[i - 1][j - 1] - (int)st.size());
            }
        }
        return res;
    }
};
