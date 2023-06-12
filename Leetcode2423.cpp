class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char, int> m, mm;
        for (auto c: word) m[c]++;
        set<int> s;
        for(auto& [k, v]: m) s.insert(v), mm[v]++;

        if (s.size() == 1)
        {
            return *s.begin() == 1 || mm[*s.begin()] == 1;
        }

        if (s.size() == 2)
        {
            int a = *s.begin();
            int b = *(++s.begin());

            if (a + 1 == b && mm[b] == 1) return true; 
            if (a == 1 && mm[1] == 1) return true;
        }

        return false;
    }
};
