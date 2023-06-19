class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        // 将物品按价格升序排序
        sort(items.begin(), items.end(), [](auto& item1, auto& item2) {
            return item1[0] < item2[0]; 
        });
        int n = items.size();
        // 按定义修改美丽值
        for (int i = 1; i < n; ++i) items[i][1] = max(items[i][1], items[i-1][1]);
        // 二分查找处理查询
        function<int(int)> query = [&](int q)
        {
            if (q >= items.back()[0]) return items.back()[1];
            if (q < items[0][0]) return 0;
            int l = 0, r = n - 1;
            while (l < r){
                int mid = (l + r + 1) / 2;
                if (items[mid][0] <= q) l = mid;
                else r = mid - 1;
            }
            return items[l][1];
        };
        
        vector<int> res;
        for (int q: queries){
            res.push_back(query(q));
        }
        return res;
    }
};
