class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> arr[2];
        int n = nums.size();
        vector<int> result(n);
        for (int i = 0; i < n; i++) arr[i % 2].push_back(nums[i]);
        sort(arr[0].begin(), arr[0].end());
        sort(arr[1].begin(), arr[1].end());
        for (int i = 0, j = 0; i < n; i += 2) result[i] = arr[0][j++];
        for (int i = 1, j = arr[1].size() - 1; i < n; i += 2) result[i] = arr[1][j--];
        return result;
    }
};
