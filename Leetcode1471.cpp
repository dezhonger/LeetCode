class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        vector<int> res(k);
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int m = arr[(n - 1) / 2], i = 0, j = n - 1, c = 0;
        while (i <= j && c < k) {
            if (abs(arr[i] - m) > abs(arr[j] - m) ||
                (abs(arr[i] - m) == abs(arr[j] - m) && arr[i] > arr[j])) {
                    res[c++] = arr[i++];
                } else {
                    res[c++] = arr[j--];
                }
        }
        return res;
    }
};
