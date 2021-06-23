class Solution {
public:
    int minDeletions(string s) {
        vector<int> c(26, 0);
        for (char ch: s) c[ch - 'a']++;
        unordered_map<int, int> cnt;
        int maxC = 0;
        for (int i = 0; i < 26; i++) {
            cnt[c[i]]++;
            maxC = max(maxC, c[i]);
        }
        int res = 0;
        for (int i = maxC; i > 0; i--) {
            if (cnt[i] > 1) {
                res += cnt[i] - 1;
                cnt[i - 1] += cnt[i] - 1;
            }
        }
        return res;
    }
};
