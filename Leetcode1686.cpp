
//https://blog.csdn.net/qq_46105170/article/details/111463831
class Solution {
public:
    typedef long long LL;
    int sgn(int x) {
        return x == 0 ? 0 : (x < 0 ? -1 : 1);
    }

    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = aliceValues.size(), v = 0;
        vector<vector<int>> s(n);
        for (int i = 0; i < n; i++) s[i] = {aliceValues[i], bobValues[i]};
        sort(s.begin(), s.end(), [](const vector<int>& a, const vector<int>& b){
            int z1 = a[0] + a[1];
            int z2 = b[0] + b[1];
            //不能写 >=, 否则内部排序会越界，类似于java
            return z1 > z2;
        });
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) v += s[i][0];
            else v -= s[i][1];
        }
        return sgn(v);
    }
};
