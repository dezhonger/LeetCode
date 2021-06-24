typedef long long LL;
int mod = (int)1e9 + 7;

class Solution {
public:
    vector<int> s;
    inline int get(int l, int r) {
        return s[r + 1] - s[l];
    }

    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        LL ans = 0;
        s = vector<int>(n + 1);
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];
        for (int i = 1; i < n - 1; i++) {
            int l = i, r = n - 2;
            int left = get(0, i - 1);
            //找到最小的地方满足left <= mid
            while (l < r) {
                int mid = l + r >> 1;
                if (get(i, mid) >= left) r = mid;
                else l = mid + 1;
            }
            //以后left只会更大，因此不会有结果了
            if (get(i, l) < left) break;
            //mid是有可能减少的，因为虽然left一直变大，mid是比left大的最小值，是个滑动窗口
            if (get(i, l) > get(l + 1, n - 1)) continue;
            int small = l;
            //找到最大的一个地方满足mid <= right
            r = n - 2;
            while (l < r) {
                int mid = l + r + 1 >> 1;
                int s1 = get(i, mid), s2 = get(mid + 1, n - 1);
                if (s1 <= s2) l = mid;
                else r = mid - 1;
            }
            int large = l;
            ans += large - small + 1;
            ans %= mod;
        }
        return ans;
    }
};
