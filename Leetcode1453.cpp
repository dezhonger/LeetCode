//https://www.acwing.com/solution/content/13319/
class Solution {
public:
    const double eps = 1e-8;

    double sqr(double x) {
        return x * x;
    }

    double dis_sqr(double x1, double y1, double x2, double y2) {
        return sqr(x1 - x2) + sqr(y1 - y2);
    }

    double dis(double x1, double y1, double x2, double y2) {
        return sqrt(dis_sqr(x1, y1, x2, y2));
    }

    void center(double x1, double y1, double x2, double y2, double r,
                double &rx1, double &ry1, double &rx2, double &ry2) {

        double midx = (x1 + x2) / 2;
        double midy = (y1 + y2) / 2;
		// 中间的距离
        double half_d = dis(midx, midy, x1, y1);

		// 求出长度为 r，起点为 (x1, y1)，方向朝向 (x2, y2) 的向量 (vx, vy)。
        double vx = (midx - x1) / half_d * r;
        double vy = (midy - y1) / half_d * r;

		// 求出 (x1, y1) 到圆心与其到中点的角的余弦值 cos_t 和正弦值 sin_t。
        double cos_t = (half_d / r);
        double sin_t = sqrt(1 - sqr(cos_t));

		// 将向量 (vx, vy) 逆时针旋转 t 和 -t，根据旋转公式，可以得到两组圆心。
		// 向量旋转公式
        rx1 = vx * cos_t - vy * sin_t + x1;
        ry1 = vx * sin_t + vy * cos_t + y1;

        rx2 = vx * cos_t + vy * sin_t + x1;
        ry2 = -vx * sin_t + vy * cos_t + y1;
    }

    int check(const vector<vector<int>>& points, double rx, double ry, double r) {
        int n = points.size();
        int cnt = 0;

        for (int k = 0; k < n; k++)
            if (dis(rx, ry, points[k][0], points[k][1]) <= r + eps)
                cnt++;

        return cnt;
    }

    int numPoints(vector<vector<int>>& points, int r) {
        int n = points.size();

        int ans = 1;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                double ds = dis_sqr(points[i][0], points[i][1], points[j][0], points[j][1]);
                if (ds == 0 || ds > 4 * sqr(r))
                    continue;

                double rx1, ry1, rx2, ry2;
                center(points[i][0], points[i][1], points[j][0], points[j][1], r,
                       rx1, ry1, rx2, ry2);

                ans = max(ans, check(points, rx1, ry1, r));
                ans = max(ans, check(points, rx2, ry2, r));

                if (ans == n)
                    return ans;
            }

        return ans;
    }
};
