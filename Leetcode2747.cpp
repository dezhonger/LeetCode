class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>> &logs, int x, vector<int> &queries) {
        int nq = queries.size(), id[nq], cnt[n + 1];
        memset(cnt, 0, sizeof(cnt));
        iota(id, id + nq, 0);
        sort(id, id + nq, [&](int i, int j) {
            return queries[i] < queries[j];
        });
        sort(logs.begin(), logs.end(), [](const auto &a, const auto &b) {
            return a[1] < b[1]; // 按照 time 排序
        });

        vector<int> ans(nq);
        int out_of_range = n, left = 0, right = 0;
        for (int i: id) {
            while (right < logs.size() && logs[right][1] <= queries[i]) // 进入窗口
                if (cnt[logs[right++][0]]++ == 0)
                    out_of_range--;
            while (left < logs.size() && logs[left][1] < queries[i] - x) // 离开窗口
                if (--cnt[logs[left++][0]] == 0)
                    out_of_range++;
            ans[i] = out_of_range;
        }
        return ans;
    }
};
