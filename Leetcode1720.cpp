class Solution {
public:
    vector<int> decode(vector<int>& a, int first) {
		vector<int> res;
		res.push_back(first);
		for (auto x : a) {
			res.push_back(first ^ x);;
			first ^= x;
		}
		return res;
    }
};
