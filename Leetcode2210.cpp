class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int res = 0, n = nums.size();
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            if (i == 0 || nums[i] != nums[i - 1]) arr.push_back(nums[i]);
        }

        int m = arr.size();
        for (int i = 1; i < m - 1; i++)
        {
            bool x = (arr[i] < arr[i + 1] && arr[i] < arr[i - 1]);
            bool y = (arr[i] > arr[i + 1] && arr[i] > arr[i - 1]);
            if (x || y) res++;
        }

        return res;
    }
};
