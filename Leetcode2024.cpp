class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int n = s.size(), l = 0, ans = 0;
        vector<int> c(2);
        for (int r = 0; r < n; r++) {
            c[s[r] == 'T']++;
            if (c[0] > k && c[1] > k) c[s[l++] == 'T']--;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
