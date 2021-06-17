class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int pre = arr[0], consecutive = 0;
        int n = arr.size();
        for (int i = 1; i < n; i++) {
            if (pre > arr[i]) consecutive++;
            else consecutive = 1, pre = arr[i];
            if (consecutive == k) return pre;
        }
        return pre;
        
    }
};
