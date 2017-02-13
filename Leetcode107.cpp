#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;



  struct TreeNode {
      int val;
     TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

struct P
{
    TreeNode* root;
    int level;
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<P> Q;
        P tmp;
        tmp.level = 1;
        tmp.root = root;
        Q.push(tmp);
        vector<int> ans1;
        int curLevel = 1;
        while(!Q.empty()) {
            P tmp2 = Q.front();
            Q.pop();
            if(tmp2.root->left != NULL) {
                P tmp3;
                tmp3.level = tmp2.level + 1;
                tmp3.root = tmp2.root->left;
                Q.push(tmp3);
            }
            if(tmp2.root->right != NULL) {
                P tmp3;
                tmp3.level = tmp2.level + 1;
                tmp3.root = tmp2.root->right;
                Q.push(tmp3);
            }
            if(tmp2.level != curLevel) {
                ans.push_back(ans1);
                ans1.clear();
                curLevel++;
            }
            ans1.push_back(tmp2.root->val);
        }
        if(ans1.size() != 0) ans.push_back(ans1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
