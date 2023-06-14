class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;
        for (auto& s: details)
        {
            int age = stoi(s.substr(11, 2));
            if (age > 60) res++;
        }

        return res;
    }
};
