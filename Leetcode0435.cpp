class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        int res = 0, n = intervals.size();
        int e = INT_MIN;
        for (int i = 0; i < n; i++) {
            int x = intervals[i][0], y = intervals[i][1];
            if (x >= e) {
                //没有重叠
                e = y;
                res++;
            }
        }
        return n - res;
    }
};
