class Solution {
public:
    int get(string s) {
        return 60 * stoi(s.substr(0, 2)) + stoi(s.substr(3));
    }
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> v;
        vector<string> res;
        for (int i = 0; i < keyName.size(); i++) {
            v[keyName[i]].push_back(get(keyTime[i]));
        }
        for (auto& [a, b]: v) {
            sort(b.begin(), b.end());
            for (int i = 0; i < b.size(); i++) {
                if (i + 2 < b.size() && b[i + 2] - b[i] <= 60) {
                    res.push_back(a);
                    break;
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
