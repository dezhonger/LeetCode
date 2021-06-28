
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        deque<int> d;
        int n = nums.size();
        vector<int> f(n);
        f[0] = nums[0];
        d.push_back(0);
        
        for (int i = 1; i < n; i++) {
            while (d.size() && d.front() < i - k) d.pop_front();
            f[i] = f[d.front()] + nums[i];
            while (d.size() && f[d.back()] <= f[i]) d.pop_back();
            d.push_back(i);
        }
        return f[n - 1];
    }
};
