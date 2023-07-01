class Solution {
public:
    int halveArray(vector<int>& nums) {
        double total = accumulate(nums.begin(), nums.end(), 0.0);   // 数组和
        int n = nums.size();
        vector<double> arr(nums.begin(), nums.end());
        make_heap(arr.begin(), arr.end());
        double dec = 0.0;   // 数组和减少的数值
        int res = 0;   // 减少操作的次数
        while (dec < total / 2) {
            // 单次操作：记录并弹出最大值，修改后重新添加进堆
            pop_heap(arr.begin(), arr.end());
            dec += arr.back() / 2;
            arr.back() /= 2;
            ++res;
            push_heap(arr.begin(), arr.end());
        }
        return res;
    }
};
