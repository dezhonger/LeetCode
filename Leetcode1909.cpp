class Solution {
public:

    bool check(vector<int>& a) {
        for (int i = 1; i < a.size(); i++) {
            if (a[i - 1] >= a[i]) return 0;
        }
        return 1;
    }
    bool canBeIncreasing(vector<int>& a) {
        if (check(a)) return 1;
        int n = a.size();
        for (int i = 0; i < n; i++) {
            vector<int> b;
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                b.push_back(a[j]);
            }
            if (check(b)) return 1;
        }
        return 0;
    }
};
