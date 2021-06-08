class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> z(2, 0);
        for (int x: students) z[x]++;
        for (int i = 0; i < sandwiches.size(); i++) {
            if (z[sandwiches[i]] == 0) return sandwiches.size() - i; 
            z[sandwiches[i]]--;
        }
        return 0;
    }
};
