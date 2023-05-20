class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> a = nums;
        sort(a.begin(), a.end());
        multiset<int> s;
        for (int i = a.size() - k; i < a.size(); i++) s.insert(a[i]);
        vector<int> res;
        for (int x: nums)
        {
            if (s.count(x)) 
            {
                res.push_back(x);
                // s.erase(x) will delelte all x in multiset s, it is wrong for this situation.
                s.erase(s.find(x));
            }
        }
        return res;
    }
};
