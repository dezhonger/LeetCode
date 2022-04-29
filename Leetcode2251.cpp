vector<int> alls;
int find(int x) {
	int l = 0, r = alls.size() - 1;
	while (l < r) {
		int mid = l + r >> 1;
		if (alls[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return r + 1;//为了后面使用前缀和算法，我们这里返回的下标从1开始
}

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        alls = vector<int>();
        for (auto &x: flowers) {
            alls.push_back(x[0]);
            alls.push_back(x[1]);
        }
        for (int &x: persons) alls.push_back(x);
        sort(alls.begin(), alls.end());
        alls.erase(unique(alls.begin(), alls.end()), alls.end());
        
        vector<int> sum(alls.size() + 10);
        for (auto &x: flowers) {
            sum[find(x[0])]++;
            sum[find(x[1]) + 1]--;
        }
        for (int i = 1; i < sum.size(); i++) sum[i] += sum[i - 1];
        
        vector<int> result;
        for (int &x: persons) result.push_back(sum[find(x)]);
        return result;
    }
};
