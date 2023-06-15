class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int n = nums.size();
        auto op1 = [](int x, int y) -> int { return x + y; };
        auto op2 = [](int x, int y) -> int { return x - y; };
        auto op3 = [](int x, int y) -> int { return x ^ y; };
        vector<function<int(int, int)>> ops = {op1, op2, op3};
        vector<int> vis(1001, 0);
        queue<pair<int, int>> q;
        q.emplace(start, 0);
        vis[start] = 1;
        while (!q.empty()){
            auto [x, step] = q.front();
            q.pop();
            for (int i = 0; i < n; ++i){
                for (auto& op: ops){
                    int nx = op(x, nums[i]);
                    if (nx == goal){
                        return step + 1;
                    }
                    
                    if (nx >= 0 && nx <= 1000 && !vis[nx]){
                        vis[nx] = 1;
                        q.emplace(nx, step + 1);
                    }
                }
            }
        }
        return -1;
    }
};
