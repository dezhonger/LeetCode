const int N = 100010;
//f[i]: 长度为i的LIS数组的最小结尾数字
int f[N];
int n;

int LIS(vector<int>& a) {
	int n = a.size();
	int len = 0;
	for (int i = 0; i < n; i++) {
		int x = a[i];
		f[0] = -2e9;
		int l = 0, r = len;
		while (l < r) {
			int mid = l + r + 1 >> 1;
			if (f[mid] <= x) l = mid;
			else r = mid - 1;
		}
		f[l + 1] = x;
		len = max(len, l + 1);
	}
	return len;
}

class Solution {
public:
    int ans;
    int kIncreasing(vector<int>& arr, int k) {
        ans = 0;
        int len = arr.size();
        for (int i = 0; i < k; i++) {
            vector<int> vv;
            for (int j = i; j < len; j += k) {
                vv.push_back(arr[j]);
            }
            ans += vv.size() - LIS(vv);
        }
        return ans;
    }
};
