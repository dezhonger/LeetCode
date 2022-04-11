typedef long long LL;

class Solution {
public:
    
    bool check(int v, vector<int>& a, int start, vector<LL>& sum, LL newFlowers)
    {
        // if (v==3) debug(v, a, start, sum, newFlowers);
        int n = a.size();
        if (a[n - 1] >= v) return 1;
        if (a[start] < v) return 1LL * (n - start) * v - 1LL *(sum[n] - sum[start]) <= newFlowers;
        int l = start, r = n - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (a[mid] >= v) l = mid + 1;
            else r = mid;
        }
        
        return 1LL * (n - r) * v - (sum[n] - sum[r]) <= newFlowers;
    }


    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        LL res = 0;
        vector<int> a, b;
        for (int x : flowers) {
            if (x < target) {
                a.push_back(x);
            } else {
                b.push_back(x);
            }
        }
        sort(a.rbegin(), a.rend());
        vector<LL> sum(a.size() + 1);
        for (int i = 0; i < a.size(); i++) sum[i + 1] = sum[i] + a[i];
        for (int i = 0; i <= a.size(); i++) {
            if (1LL * i * target - sum[i] > newFlowers) break;
            if (i == a.size()) {
                res = max(res, (LL)(1LL * i + b.size()) * full);
                continue;
            }
            LL remain = newFlowers - (1LL * i * target - sum[i]);
            
            int l = 0, r = target - 1;
            while (l < r) {
                int mid = (l + r + 1) / 2;
                if (check(mid, a, i, sum, remain)) {
                    LL ans = 1LL * (i + b.size()) * full + (1LL * partial * mid);
                    res = max(res, ans);
                    // debug(i, mid, ans);
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
        }

        return res;
    }
};
