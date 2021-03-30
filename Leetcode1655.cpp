//https://leetcode-cn.com/problems/minimum-initial-energy-to-finish-tasks/solution/wan-cheng-suo-you-ren-wu-de-zui-shao-chu-shi-neng-/

#define ps push_back
struct fun {
    int diff, act, mini;
    bool operator< (fun const &w) const {
        if (diff != w.diff) return w.diff < diff;
        return w.mini < mini;
    }
};
class Solution {
public:
    
    int minimumEffort(vector<vector<int>>& tasks) {
        int ans = 0, cur = 0;
        
        vector<fun> v;
        int n = tasks.size();
        for (auto& x : tasks) v.ps({x[1] - x[0], x[0], x[1]});
        sort(v.begin(), v.end());
        
        for (int i = 0; i < n; i++) {
            fun f = v[i];
            //cout << cur << " " << f.mini << " " << f.act << endl;
            if (cur < f.mini) {
                
                ans += f.mini - cur;
                cur = f.mini;
            }  
            cur -= f.act;
            //cout << ans << endl;
        }
        return ans;
        
    }
};