#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    //H2O H2O
    //Mg(OH)2 H2MgO2
    //K4(ON(SO3)2)2  K4N2O14S4
    //Be32 Be32
    
    
    string countOfAtoms(string f) {
        map<string, int> m;
        stack<pair<string, int>> s;
        int n = f.size();
        for (int i = 0; i < n; i++) {
            if (isupper(f[i])) {
                //是元素名
                string str(1, f[i]);
                int j = i + 1;
                while (j < n && islower(f[j])) str += f[j++];
                i = j - 1;
                
                //计算数字
                int cnt = 0;
                if (!isdigit(f[i + 1])) cnt = 1;
                else {
                    int j = i + 1;
                    while (j < n && isdigit(f[j])) cnt = cnt * 10 + f[j++] - '0';
                }
                i = j - 1;
                //cout << "? " << str << " " << cnt << endl; 
                s.push({str, cnt});
            } else if (f[i] == '(') {
                s.push({"(", 1});
            } else if (f[i] == ')') {
                int cnt = 0;
                int j = i + 1;
                while (j < n && isdigit(f[j])) cnt = cnt * 10 + f[j++] - '0';
                if (cnt == 0) cnt = 1;
                i = j - 1;
                stack<pair<string, int>> t;
                
                while (s.size()) {
                    auto p = s.top();
                    //cout << "1 " << p.first << " " << p.second << endl;
                    s.pop();
                    if (p.first == "(") break;
                    t.push({p.first, p.second * cnt});
                }
                while (t.size()) {
                    auto p = t.top();
                    t.pop();
                    s.push({p.first, p.second});
                }
            } else {
                //cannot reach here 
            }
        }
        map<string, int> res;
        while (s.size()) {
            auto x = s.top();
            res[x.first] += x.second;
            s.pop();
        }
        string ans;
        for(auto& x : res) {
            //cout << x.first << " " << x.second << endl;
            ans += x.first;
            if (x.second > 1) ans += to_string(x.second);
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.countOfAtoms("H2O") << endl;
    cout << s.countOfAtoms("K4(ON(SO3)2)2") << endl;
    cout << s.countOfAtoms("Be32") << endl;
    cout << s.countOfAtoms("Mg(OH)2") << endl;
    cout << s.countOfAtoms("Mg(H2O)N") << endl;
    return 0;
    
}
