class Solution {
public:
    vector<int> getConcatenation(vector<int>& a) {
        int n = a.size();
        vector<int> ans(n * 2);
        for (int i = 0; i < n; i++) ans[i] = a[i];
        for (int i = n; i < n + n; i++) ans[i] = a[i - n];
        return ans;
    }
};
