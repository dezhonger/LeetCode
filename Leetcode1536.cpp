class Solution {
public:
    int cal(vector<int>& a) {
        int i = a.size() - 1;
        while (i >= 0 && a[i] == 0) i--;
        return a.size() - 1 - i;
        
    }
    int minSwaps(vector<vector<int>>& g) {
        int n = g.size(), res = 0;
        for (int i = 0; i < n; i++) {
            int k = -1;
            for (int j = i; j < n; j++) {
                if (cal(g[j]) >= (n - i - 1)) {
                    k = j;
                    break;
                }
            }
            if (k == -1) return -1;
            if (k == i) continue;
            res += k - i;
            for (int j = k - 1; j >= i; j--) swap(g[j], g[j + 1]);
        }
        return res;
    }
};
