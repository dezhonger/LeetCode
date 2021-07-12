const int N = 100010;

int LIS(vector<int> & v) {
    //f[i]: 长度为i的LIS数组的最小结尾数字
    int len = 0;
    vector<int> f(N);
    for (int x: v) {
        f[0] = -2e9;
        int l = 0, r = len;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (f[mid] < x) l = mid;
            else r = mid - 1;
        }
        f[l + 1] = x;
        len = max(len, l + 1);
    }
    return len;
}

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp;
        int idx = 0;
        for (int x: target) {
            if (!mp.count(x)) mp[x] = ++idx;
        }
        vector<int> v;
        for (int x: arr) {
            if (mp.count(x)) v.push_back(mp[x]);
        }
        return target.size() - LIS(v);
    }
};
