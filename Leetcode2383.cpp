class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int n = energy.size(), e1 = initialEnergy, e2 = 0;
        for (int i = 0; i < n; i++)
        {
            initialEnergy -= energy[i];
            if (initialExperience <= experience[i]) {
                int add = experience[i] - initialExperience + 1;
                e2 += add;
                initialExperience += add;
            }
            initialExperience += experience[i];
            e1 = min(e1, initialEnergy);
        }

        if (e1 > 0) return e2;
        return 1 - e1 + e2;
    }
};
