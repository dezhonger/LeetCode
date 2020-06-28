class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(), salary.end());
        double s = 0;
        int sz = salary.size();
        for (int i = 1; i < sz - 1; i++) s += salary[i];
        return 1.0 * s / (sz - 2);
    }
};