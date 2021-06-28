typedef long long LL;
const int N = 10005;
int mod = (int)1e9 + 7;


class Solution {
public:

    long long wonderfulSubstrings(string s) {

        int n = s.size();
        vector<int> c2(10000);
        c2[0] = 1;
        LL res = 0;
        int a = 0;
        for (int i = 0; i < n; i++) {
            int x = s[i] - 'a';
            a ^= (1 << x);
            for (int j = 0; j < 10; j++) {
                int k = (1 << j);
                int k2 = a ^ k;
                res += c2[k2];
            }
            res += c2[a];
            c2[a]++;
            
        }
        return res;
    }
};
