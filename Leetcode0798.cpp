#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int n;
    vector<int> a;
    
    void f(int pos, vector<int>& sum) {
        int x = a[pos];
        //x可以得分的区间为[x, n]
        //我们计算轮转多少次可以将a[i]移动到[x, n - 1];
        if (pos < x) {
            //移动的是一个连续的区间
            int i = pos + n - x;
            //[pos + 1, i]
            cout << (pos + 1) << " " << i << endl;
            sum[(pos + 1)]++;
            sum[i + 1]--;
        } else if (pos == 0) {
            if (x == 0) sum[0]++, sum[n--];
            else sum[1]++, sum[n - x + 1]--;
        }
        else if (pos == n - 1) {
            //[0, n - 1 - pos];
            cout << 0 << " " << n - 1 - x << endl;
            sum[0]++;sum[n-x]--;
        } else {
            //移动的两段区间
            //[0, pos - x]
            //[pos + 1, n - 1]
            cout << 0 << " " << pos - x << "  ...." << pos + 1 << " " << n - 1 << endl;
            sum[0]++;
            sum[pos - x + 1]--;
            sum[pos + 1]++;;
            sum[n]--;
        }
    }

    int bestRotation(vector<int>& A) {
        a = A;
        n = a.size();
        //找到每一个数可以得分的区间
        vector<int> sum(n + 5, 0);
        for (int i = 0; i < n; i++) {
            
            //cout << i << " ";
            f(i, sum);
        }
        int maxV = -1;
        int ans = 0;
        for (int i = 1; i < n; i++) sum[i] += sum[i - 1];
        //for (int i = 0; i < n; i++) cout << sum[i] << " ";cout << endl;
        
        for (int i = 0; i < n; i++) {
            if (sum[i] > maxV) {
                maxV = sum[i];
                ans = i;
            }
        }
        cout << maxV << " " << ans << endl << endl;
        return ans;
    }
};
int main() {
    Solution s;
    vector<int> v1 = {2, 3, 1, 4, 0};
    vector<int> v2 = {1, 3, 0, 2, 4};
    vector<int> v3 = {0, 3, 1, 3, 1};
    //cout << s.bestRotation(v1) << endl;
    //cout << s.bestRotation(v2) << endl;
    cout << s.bestRotation(v3) << endl;
    return 0;
}