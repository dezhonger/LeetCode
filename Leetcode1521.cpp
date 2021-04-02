class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        //&运算是单调递减的,且不同的值最多只有20个(&运算只会把1变为0)
        int n = arr.size();
        set<int> s;
        int ans = INT_MAX;
        for (int r = 0; r < n; r++) {
            ans = min(ans, abs(target - arr[r]));
            set<int> s2;
            for (int x : s) {
                int t = x & arr[r];
                s2.insert(t);
                ans = min(ans, abs(t - target));
            }
            s2.insert(arr[i]);
            s = s2;
        }
        return ans;
    }
};