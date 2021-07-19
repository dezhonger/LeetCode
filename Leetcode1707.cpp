
const int N = 3000010;
int son[N][2], cnt[N];
int idx;
class Solution {
public:
    
    void insert(int x) {
        int p = 0;
        for (int i = 30; i >= 0; i--) {
            int v = x >> i & 1;
            if (!son[p][v]) son[p][v] = ++idx;
            p = son[p][v];
        }
    }
    
    int query(int x) {
        int p = 0, res = 0;
        for (int i = 30; i >= 0; i--) {
            int v = x >> i & 1;
            if (son[p][v ^ 1]) {
                res |= (1 << i);
                p = son[p][v ^ 1];
            } else {
                p = son[p][v];
            }
        }
        return res;
    }
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size(), m = nums.size();
        vector<int> res(n);
        for (int i = 0; i < n; i++) queries[i].emplace_back(i);
        sort(queries.begin(), queries.end(), [](const vector<int>& a, const vector<int>& b) {
           return a[1] < b[1];
        });
        sort(nums.begin(), nums.end());
        int j = 0;
        memset(son, 0, sizeof son);
        idx = 0;
        for (int i = 0; i < n; i++) {
            while (j < m && nums[j] <= queries[i][1]) insert(nums[j++]);
            if (j) res[queries[i][2]] = query(queries[i][0]);
            else res[queries[i][2]] = -1;
            
        }
        return res;
    }
};
