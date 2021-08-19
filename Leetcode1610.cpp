class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        // 极角排序
        int c = 0;
        vector<double> vd;
        for (auto& p: points) {
            if (p == location) c++;
            else {
                //atan2 取值范围为 (-π，+π](−π，+π]。当 atan2 的返回值为正表示从 X 轴逆时针旋转的角度，返回值为负表示从 X 轴顺时针旋转的角度。
                vd.push_back(atan2(p[1] - location[1], p[0] - location[0]));
            }
        }
        sort(vd.begin(), vd.end());
        const double PI = acos(-1);
        int n = vd.size();
        for (int i = 0; i < n; i++) vd.push_back(vd[i] + 2 * PI);
        int ans = 0;
        for (int i = 0, j = 0; i < 2 * n; i++) {
            while(j < 2 * n && vd[j] - vd[i] <= angle * PI / 180) j++;
            ans = max(j - i, ans);
        }
        return ans + c;
    }
};
