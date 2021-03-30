//https://www.acwing.com/solution/content/4607/
//https://www.acwing.com/activity/content/code/content/432632/

#define vi vector
#define pb push_back
#define F first
#define S second
#define PII pair<int, int>
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vi<vi<int>> res;
        vi<PII> points;
        multiset<int> heights;
        
        for (auto& b: buildings) {
            points.pb({b[0], -b[2]});
            points.pb({b[1], b[2]});
        }
        
        sort(points.begin(), points.end());
        heights.insert(0);
        
        for (auto& p : points) {
            int x = p.F, h = abs(p.S);
            if (p.S < 0) { //左端点
                //是最大值
                if (h > *heights.rbegin()) res.pb({x, h});
                heights.insert(h);
            } else { //右端点
                heights.erase(heights.find(h));
                if (h > *heights.rbegin()) res.pb({x, *heights.rbegin()});
            }
        }
        return res;
    }
};