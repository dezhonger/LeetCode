#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int f[N][N];
int c[N][N];
class Solution {
public:

    

    int cal(vector<int>& h, int i, int j) {
        if (c[i][j] != -1) return c[i][j];
        i--;j--;
        int sz = j - i + 1;
        int ans = i + sz / 2;
        int cost = 0;
        for (int k = i; k <= j; k++) {
            cost += abs(h[ans] - h[k]);
        }
        return c[i][j] = cost;
    }

    int minDistance(vector<int>& houses, int k) {
        memset(f, 0x3f, sizeof f);
        memset(c, -1, sizeof c);
        int n = houses.size();
        if (n <= k) return 0;
                
        sort(houses.begin(), houses.end());
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= min(i, k); j++) {
                for (int k = 1; k <= i; k++) {
                    
                    int cost = cal(houses, i - k + 1, i);
                    //if (i == 4 && j == 2 && k == 1) cout << "cost " << cost << endl;
                    if (i - k <= j - 1) {
                        f[i][j] = min(f[i][j], cost);
                    } else {
                        f[i][j] = min(f[i][j], f[i - k][j - 1] + cost);
                    }
                }
            }
        }
        //for (int i = 1; i <= n; i++) cout << f[i][k] << " " << endl;

        return f[n][k];
    }
};

int main() {
    Solution s;
    vector<int> v = {2,3,5,12,18};
    //vector<int> v = {2,5};
    cout << s.minDistance(v, 2) << endl;
}