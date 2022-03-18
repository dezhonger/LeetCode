// __builtin_popcount

typedef long long LL;

class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int m = nums.size(), n = m / 3;
        vector<LL> p1(n + 1);
        priority_queue<int> q1; //大根堆
        priority_queue<int, vector<int>, greater<int>> q2;
       
        LL sum =  0;
        for (int i = 0; i < n; i++) sum += nums[i], q1.push(nums[i]);
        p1[0] = sum;
        for (int i = n; i < n + n; i++) {
            sum += nums[i];
            q1.push(nums[i]);
            sum -= q1.top();
            q1.pop();
            p1[i - (n - 1)] = sum;
        }
        
        LL p2 = 0;
        for (int i = n * 3 - 1; i >= n + n; i--) p2 += nums[i], q2.push(nums[i]);
        LL ans = p1[n] - p2;
        for (int i = n * 2 - 1; i >= n; i--) {
            p2 += nums[i];
            q2.push(nums[i]);
            p2 -= q2.top();
            q2.pop();
            ans = min(ans, p1[i - n] - p2);
        }
        return ans;
    }
};
