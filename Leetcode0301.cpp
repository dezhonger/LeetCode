#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;
bool isValid(string s) {
    int a = 0;
    for(int i = 0; i < s.size(); i++) {
        int b = 0;
        if(s[i] == '(') b = 1;
        else if(s[i] == ')') b = -1;
        a += b;
        if(a < 0) return false;
    }
    return a == 0;
}

vector<string> removeInvalidParentheses(string s) {
    vector<string> ans;
    if(l == null) return ans;
    int l = s.size();
    set<string> S;
    queue<string> q;
    q.push(s);
    S.insert(s);
    bool flag = false;
    while(!q.empty()) {
        string tmp = q.front();
        q.pop();
        if(isValid(tmp)) {
            flag = true;
            ans.push_back(tmp);
        }
        if(flag) continue;
        for(int k = 0; k < tmp.size(); k++) {
            if(tmp[k] != '(' && tmp[k] != ')') continue;
            string temp = tmp.substr(0, k) + tmp.substr(k + 1);
            if(S.find(temp) == S.end()) {S.insert(temp); q.push(temp);}
        }
    }
    return ans;
}

int main()
{
    vector<string> ans = removeInvalidParentheses("()())()");
    cout << ans.size() << endl;
    for(auto it = ans.begin(); it != ans.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}
