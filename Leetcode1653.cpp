class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();

        vector<int> l(n + 2), r(n + 2);
        for (int i = 1, j = n; i <= n; j--, i++) {
            l[i] = l[i - 1] + (s[i - 1] == 'b');
            r[j] = r[j + 1] + (s[j - 1] == 'a');
        }
        int ans = n + 1;
        for (int i = 1; i <= n + 1; i++) ans = min(ans, l[i - 1] + r[i]);
        return ans;
    }
};
