class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& a, vector<int>& b) {
        vector<vector<int>> res;
        int k = 0, n = a.size();
        //先把b区间左边和b没有交集的加入到答案里
        while (k < n && a[k][1] < b[0]) res.push_back(a[k++]);
        //合并有交集的区间，并加入到答案里
        if (k < n) {
            b[0] = min(b[0], a[k][0]);
            while (k < n && a[k][0] <= b[1]) b[1] = max(b[1], a[k++][1]);
        }
        res.push_back(b);
        //把在b区间右边和b没有交集的加入到答案里
        while (k < n) res.push_back(a[k++]);
        return res;
    }
};
