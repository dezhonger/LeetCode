typedef long long LL;
int mod = (int)1e9 + 7;

class Solution {
public:
    int maxD(vector<int>& a) {
        sort(a.begin(), a.end());
        int maxV = a[0];
        for (int i = 1; i < a.size(); i++) {
            maxV = max(maxV, a[i] - a[i - 1]);
        }
        return maxV;
    }

    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        return 1LL * maxD(horizontalCuts) * maxD(verticalCuts) % mod;
    }
};
 
