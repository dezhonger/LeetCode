#include <bits/stdc++.h>
using namespace std;


//题意：给了一些点，求凸包。返回凸包的点坐标. 这里用Andrew求凸包算法实现。


class Solution {
public:

    //向量叉积 a×b = |a| * |b| * sinθ
    //θ为a旋转到b的角度，如果是逆时针为正数值，否则为负数值
    int cross(int x1, int y1, int x2, int y2) {
        return x1 * y2 - x2 * y1;
    }
    
    //求向量ab和向量ac的叉积
    int area(vector<int>& a, vector<int>& b, vector<int>& c) {
        return cross(b[0] - a[0], b[1] - a[1], c[0] - a[0], c[1] - a[1]);
    }

    //求凸包:Andrew算法，也叫作水平排序算法
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        //坐标先按照x排序，再按照y排序
        sort(points.begin(), points.end());
        int n = points.size();
        
        //记录是否已经在凸包上了
        vector<bool> used(n);
        
        //下标从1开始用，由于起点需要加入两次，因此开n+2空间
        vector<int> hull(n + 2);
        
        //栈顶下标
        int top = 0;
        
        //先求上凸包
        for (int i = 0; i < n; i++) {
            while (top >= 2 && area(points[hull[top - 1]], points[hull[top]], points[i]) > 0) {
                //逆时针的话就删掉栈顶元素。注意：如果在一条直线的话是保留的
                used[hull[top--]] = false;
            }
            hull[++top] = i;
            used[i] = true;
        }
        
        //求下凸包
        //起点还会用到，因此先置为false
        used[0] = false;
        for (int i = n - 1; i >= 0; i--) {
            if (used[i]) continue;
            while (top >= 2 && area(points[hull[top - 1]], points[hull[top]], points[i]) > 0) {
                //这里和上面是相同的
                top--;
            }
            hull[++top] = i;
            //这里used就不管了，因为也不会再用到了
        }
        
        //起点被加了两次，这里去掉
        top--;
        
        vector<vector<int>> res;
        for (int i = 1; i <= top; i++) res.push_back(points[hull[i]]);
        return res;
    }
};