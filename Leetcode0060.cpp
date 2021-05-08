const int N = 10;
class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        vector<bool> v(n + 1, false);
        vector<int> f(N);
        f[0] = 1;
        for (int i = 1; i < N; i++) f[i] = f[i - 1] * i;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= n; j++) {
                if (!v[j]) {
                    if (k <= f[n - i - 1]) {
                        res += to_string(j);
                        v[j] = true;
                        break;
                    } else {
                        k -= f[n - i - 1];
                    }
                }
            }
        }
        return res;
    }
};

