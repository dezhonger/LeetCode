#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

class Solution {
public:
    vector<int> a;
    
    int n;
    
    vector<int> cal1() {
        vector<int> res(n, -1);
        vector<pair<int, int>>  vp;
        for (int i = 0; i < n; i++) vp.push_back({a[i], i});
        sort(vp.begin(), vp.end());
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (st.empty() || vp[st.top()].F > vp[i].F) st.push(i);
            else {
                while (st.size() && vp[st.top()].F <= vp[i].F) {
                    int index = vp[st.top()].S;
                    int ans = vp[i].S;
                    if (ans > index) {
                        res[index] = ans;
                        st.pop();
                    } else {
                        break;
                    }
                    
                }
                st.push(i);
            } 
        }
        return res;
    }
    
    vector<int> cal2() {
        vector<int> res(n, -1);
        vector<pair<int, int>>  vp;
        for (int i = 0; i < n; i++) vp.push_back({-a[i], i});
        sort(vp.begin(), vp.end());
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (st.empty() || vp[st.top()].F > vp[i].F) st.push(i);
            else {
                while (st.size() && vp[st.top()].F <= vp[i].F) {
                    int index = vp[st.top()].S;
                    int ans = vp[i].S;
                    if (ans > index) {
                        res[index] = ans;
                        st.pop();
                    } else {
                        break;
                    }
                }
                st.push(i);
            } 
        }
        return res;
    }
    
    

    
    int oddEvenJumps(vector<int>& arr) {
        n = arr.size();
        a = arr;
        vector<int> a1 = cal1();
        vector<int> a2 = cal2();
        //for (int i = 0; i < n; i++) cout << a1[i] << " "; cout << endl;
        //for (int i = 0; i < n; i++) cout << a2[i] << " "; cout << endl;
        
        int res = 0;
        vector<bool> even(n, 0);
        vector<bool> odd(n, 0);
        even[n - 1] = odd[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (a2[i] != -1) even[i] = odd[a2[i]];
            if (a1[i] != -1) odd[i] = even[a1[i]];
        }
        for (int i = 0; i < n; i++) {
            if (odd[i]) res++;
        }
        return res;
        
    }
};

int main() {

    Solution s;
    //vector<int> ss = {10,13,12,14,15};
    vector<int> ss = {5, 1, 3, 4, 2};
    //vector<int> ss = {2, 3, 1, 1, 4};
    cout << s.oddEvenJumps(ss) << endl;
    return 0;
}
