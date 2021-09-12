class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
      int n = arr.size();
      // 维护左/右边连续递增的最大值
      int lmax = 0, rmax = n - 1;
      for (int i = 1; i < n; i++) {
        if (arr[i] >= arr[i - 1]) lmax = i;
        else break;
      }
      for (int i = n - 2; i >= 0; i--) {
        if (arr[i] <= arr[i + 1]) rmax = i;
        else break;
      }

      int ans = min(n - 1 - lmax, rmax);
      for (int i = lmax, r = n; i >= 0; i--) {
        while (r - 1 >= rmax && i < r - 1 && arr[i] <= arr[r - 1]) r--;
        ans = min(ans, r - i - 1);
      }
      for (int i = rmax, l = -1; i < n; i++) {
        while (l + 1 <= lmax && i > l + 1 && arr[i] >= arr[l + 1]) l++;
        ans = min(ans, i - l - 1);
      }
      return ans;
    }
};
