class Solution {
public:
    int countQuadruplets(vector<int>& a) {
        int n = a.size(), r = 0;
        for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) for (int k = j + 1; k < n; k++) for (int l = k + 1; l < n; l++) {
            if (a[i] + a[j] + a[k] == a[l]) r++;
        }
        return r;
    }
};
