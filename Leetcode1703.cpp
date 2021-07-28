//https://leetcode-cn.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/solution/de-dao-lian-xu-k-ge-1-de-zui-shao-xiang-lpa9i/
class Solution {
public:
    int minMoves(vector<int>& a, int k) {
        int n = a.size(), ans = INT_MAX;
        vector<int> g;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1) g.push_back(i - g.size());
        }
        int cnt = g.size();
        vector<int> s(cnt + 1);
        for (int i = 1; i <= cnt; i++) s[i] = g[i - 1] + s[i - 1];
        for (int i = 0; i + k <= cnt; i++) {
            int r = i + k - 1, mid = (i + r) / 2, gmid = g[mid];
            int tmp = (2 * mid - 2 * i - k + 1) * gmid + (s[i + k] - s[mid + 1]) - (s[mid] - s[i]);
            ans = min(ans, tmp);
        }
        return ans;
    }
};
