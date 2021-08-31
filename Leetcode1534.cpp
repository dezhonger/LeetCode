class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int res = 0, n = arr.size();
        vector<int> s(1010, 0);
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (abs(arr[j] - arr[k]) > b) continue;
                // arr[i]需要满足下面的条件
                // [arr[j] - a, arr[j] + a]
                // [arr[k] - c, arr[k] + c]
                
                int l = max(arr[j] - a, arr[k] - c);
                int r = min(arr[j] + a, arr[k] + c);
                if (l <= r && r >= 0) {
                    l = max(l, 0);
                    r = min(r, 1000);
                    if (l) res += s[r] - s[l - 1];
                    else res += s[r];
                }
            }
            for (int k = arr[j]; k <= 1000; k++) s[k]++;
        }
        return res;
    }
};
