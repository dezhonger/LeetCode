

const int N = 100010;
int h[N], e[N], ne[N], idx;

void add(int a, int b) {
  e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

class Solution {
public:
    vector<int> ans;
    pair<unordered_set<int>, int> dfs(int u, int fa, vector<int>& nums) {
      unordered_set<int> us;
      us.insert(nums[u]);
      int maxV = 1;
      for (int i = h[u]; ~i; i = ne[i]) {
        auto res = dfs(e[i], u, nums);
        if (us.size() < res.first.size()) swap(us, res.first);
        for (auto& x: res.first) us.insert(x);
        maxV = max(maxV, res.second);
      }
      while (us.count(maxV)) maxV++;
      ans[u] = maxV;
      return {move(us), maxV};

    }
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
      idx = 0;
      memset(h, -1, sizeof h);
      for (int i = 1; i < parents.size(); i++) add(parents[i], i);
      ans.resize(parents.size());
      dfs(0, -1, nums);
      return ans;
    }
};
