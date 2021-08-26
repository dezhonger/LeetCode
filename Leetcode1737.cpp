class Solution {
public:
    int minCharacters(string a, string b) {
        int n = a.size(), m = b.size();
        int ans = INT_MAX;
        for (int i = 0; i < 25; i++) {
            int s = 0;
            for (int j = 0; j < n; j++) if (a[j] - 'a' > i) s++;
            for (int j = 0; j < m; j++) if (b[j] - 'a' < i + 1) s++;
            ans = min(ans, s);
        }
        for (int i = 0; i < 25; i++) {
            int s = 0;
            for (int j = 0; j < m; j++) if (b[j] - 'a' > i) s++;
            for (int j = 0; j < n; j++) if (a[j] - 'a' < i + 1) s++;
            ans = min(ans, s);
        }
        for (int i = 0; i < 26; i++) {
            int s = 0;
            for (int j = 0; j < n; j++) if (a[j] - 'a' != i) s++;
            for (int j = 0; j < m; j++) if (b[j] - 'a' != i) s++;
            ans = min(ans, s);
        }
        return ans;
    }
};
