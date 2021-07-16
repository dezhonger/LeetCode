class Solution {
public:
    int find(vector<int>& f, int x) {
        return f[x] == x ? x : f[x] = find(f, f[x]);
    }
    void merge(vector<int>& f, int x, int y) {
        f[find(f, x)] = find(f, y);
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<int> f(n);
        int m = queries.size();
        vector<bool> ans(m);
        iota(f.begin(), f.end(), 0);
        for (int i = 0; i < m; i++) queries[i].push_back(i);
        sort(edgeList.begin(), edgeList.end(), [](const vector<int>& a, const vector<int>& b) {
           return a[2] < b[2];
        });
        sort(queries.begin(), queries.end(), [](const vector<int>& a, const vector<int>& b) {
           return a[2] < b[2];
        });
        for (int i = 0, j = 0; i < m; i++) {
            int len = queries[i][2];
            while (j < edgeList.size() && edgeList[j][2] < len) {
                merge(f, edgeList[j][0], edgeList[j][1]);
                j++;
            }
            ans[queries[i][3]] = (find(f, queries[i][0]) == find(f, queries[i][1]));
        }
        return ans;
    }
};
