const int N = 1010;
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<int> f(k + 1);
        int s = 0;
        for (auto& pile: piles) {
            int n = pile.size();
            for (int i = 1; i < n; i++) pile[i] += pile[i - 1];
            s = min(s + n, k);
            for (int j = s; j >= 0; j--) {
                for (int w = 1; w <= min(n, j); w++) f[j] = max(f[j], f[j - w] + pile[w - 1]);
            }
        }
        return f[k];
    }
};
