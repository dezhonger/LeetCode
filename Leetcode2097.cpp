typedef long long LL;

const int N = 100010;


void dfs(vector<vector<int>>& ans, int s, map<int, vector<int>>& edges) {
    while(!edges[s].empty()) {
        int v = edges[s].back();
        edges[s].pop_back();
        //这里的顺序很重要 https://leetcode-cn.com/problems/valid-arrangement-of-pairs/solution/zhuan-hua-wei-ou-la-lu-jing-wen-ti-tu-ji-aqmu/
        dfs(ans, v, edges);    
        ans.push_back({s, v}); 
    }

}


class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        map<int, int> in;
        map<int, int> out;
        map<int, vector<int>> edges;
        vector<vector<int>> ans;
        for (auto& e: pairs) {
            out[e[0]]++;
            in[e[1]]++;
            edges[e[0]].push_back(e[1]);
        }
        int s = pairs[0][0];
        for (auto& e: pairs) {
            if (out[e[0]] == in[e[0]] + 1) {
                s = e[0];
                break;
            }
        }
        dfs(ans, s, edges);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
