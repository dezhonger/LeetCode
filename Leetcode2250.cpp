class Solution {
public:
    vector<int> countRectangles(vector<vector<int>> &rectangles, vector<vector<int>> &points) {

        //按照纵坐标排序
        sort(rectangles.begin(), rectangles.end(), [](auto &a, auto &b) { return a[1] > b[1]; });

        int n = points.size();
        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0);
        ////按照纵坐标排序
        sort(ids.begin(), ids.end(), [&](int i, int j) { return points[i][1] > points[j][1]; });

        vector<int> ans(n), xs;
        int i = 0;
        for (int id : ids) {
            int start = i;
            while (i < rectangles.size() && rectangles[i][1] >= points[id][1])
                xs.push_back(rectangles[i++][0]);
            if (start < i) sort(xs.begin(), xs.end()); // 只有在 xs 插入了新元素时才排序
            ans[id] = xs.end() - lower_bound(xs.begin(), xs.end(), points[id][0]);
        }
        return ans;
    }
};
