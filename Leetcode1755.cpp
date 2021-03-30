#define pb push_back
class Solution {
public:
    int minAbsDifference(vector<int>& a, int b) {
        int n = a.size();
        int ans = 2e9;
        int m1 = n / 2, m2 = n - m1;
        vector<int> v1, v2;
        
        for (int s = 0; s < (1 << m1); s++) {
            int tmp = 0;
            for (int i = 0; i < m1; i++) {
                if (s >> i & 1) tmp += a[i];
            }
            ans = min(ans, abs(b - tmp));
            v1.pb(tmp);
        }
        
        for (int s = 0; s < (1 << m2); s++) {
            int tmp = 0;
            for (int i = 0; i < m2; i++) {
                if (s >> i & 1) tmp += a[i + m1];
            }
            ans = min(ans, abs(b - tmp));
            v2.pb(tmp);
        }
        
        sort(v2.begin(), v2.end());
        for (int i = 0; i < v1.size(); i++) {
            int t = b - v1[i];
            int pos = lower_bound(v2.begin(), v2.end(), t) - v2.begin();
            for (int j = pos - 1; j <= pos + 1; j++) {
                if (j >= 0 && j < v2.size()) ans = min(ans, abs(b - v2[j] - v1[i]));
            }
        }
        return ans;
    }
};
