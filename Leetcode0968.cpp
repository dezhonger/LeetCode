#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0968.cpp
//
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-07 04:15:55
//Last modified: 2021-05-07 05:13:34

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

void my_assert(bool x) {
    if (!x) {
        cout << "NO" << '\n';
        exit(0);
    }
}



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        vector<int> g(TreeNode* root, TreeNode* fa) {
            vector<int> f(4, 0);
            if (root == NULL) return f;

            vector<int> ll = g(root -> left, root);
            vector<int> rr = g(root -> right, root);

            //f[0]在该处放照相机
            if (root -> left && root -> right) f[0] = 1 + ll[3] + rr[3];
            else if (root -> left)  f[0] = 1 + ll[3];
            else if (root -> right) f[0] = 1 + rr[3];
            else f[0] = 1;

            //f[1]不放但是父亲要放，也就是说该点会被控制,
            if (fa == NULL) f[1] = 1000000;
            else {
                if (root -> left && root -> right) f[1] = min(ll[2], ll[0])
                    + min(rr[2], rr[0]);
                else if (root -> left) f[1] = min(ll[2], ll[0]);
                else if (root -> right) f[1] = min(rr[2], rr[0]);
                else f[1] = 0;
            }


            //f[2]不放且父节点也不放，也就是说子节点要放
            if (root -> left && root -> right) f[2] = min(ll[0] + min(rr[0], rr[2]),
                    min(ll[0], ll[2]) + rr[0]);
            else if (root -> left) f[2] = ll[0];
            else if (root -> right) f[2] = rr[0];
            else f[2] = 1000000;

            f[3] = min(f[0], min(f[1], f[2]));
            debug(root -> val, f);
            return f;
        }
        int minCameraCover(TreeNode* root) {
            return g(root, NULL)[3];
        }
};

int main() {
    TreeNode* r1 = new TreeNode(1);
    TreeNode* r2 = new TreeNode(2);
    TreeNode* r3 = new TreeNode(3);
    TreeNode* r4 = new TreeNode(4);
    TreeNode* r5 = new TreeNode(5);
    r1 -> left = r2;
    r2 -> left = r3;
    r3 -> left = r4;
    r4 -> left = r5;
    Solution s;
    cout << s.minCameraCover(r1) << endl;
    return 0;
}

