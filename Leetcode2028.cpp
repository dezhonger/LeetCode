class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int remain = (rolls.size() + n) * mean - accumulate(rolls.begin(), rolls.end(), 0);
        if (remain > 6 * n || remain < n) return vector<int>();
        vector<int> ans(n, remain / n);
        for (int i = 0; i < remain % n; i++) ans[i]++;
        return ans;
    }
};
