class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        int n = num.size(), r;
        for (int i = 0; i < n; i++) {
            if (change[num[i] - '0'] > (num[i] - '0')) {
                r = i;
                break;
            }
        }

        if (r == n) return num;
        while (r < n && change[num[r] - '0'] >= (num[r] - '0')) {
            num[r] = change[num[r] - '0'] + '0';
            r++;
        }
        return num;
    }
};
