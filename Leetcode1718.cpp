class Solution {
public:
    bool f = false;
    bool dfs(vector<int>& ans, vector<int>& v, int start) {
        if (f) return true;
        if (start == ans.size()) {
            f = true;
            return true;
        }
        if (ans[start] != 0) return dfs(ans, v, start + 1);
        for (int i = v.size() - 1; i >= 0; i--) {
            if (v[i]) continue;
            //优先填写最大的数
            int number = i + 1;
            int a = start, b = start + number;
            if (number == 1) b = a;
            if (ans[a] == 0 && b < ans.size() && ans[b] == 0) {
                v[i] = true;
                ans[a] = ans[b] = number;
                bool res = dfs(ans, v, start + 1);
                if (res) return true;
                ans[a] = ans[b] = 0;
                v[i] = false;
            }
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(n * 2 - 1);
        vector<int> v(n);
        dfs(ans, v, 0);
        return ans;
    }
};
