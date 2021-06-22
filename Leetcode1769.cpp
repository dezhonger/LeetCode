class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res(n);
        for (int i = 0, op = 0, cnt = 0; i < n; i++) {
            res[i] += op;
            cnt += boxes[i] == '1';
            op += cnt;
        }
        for (int i = n - 1, op = 0, cnt = 0; i >= 0; i--) {
            res[i] += op;
            cnt += boxes[i] == '1';
            op += cnt;
        }
        return res;
    }
};
