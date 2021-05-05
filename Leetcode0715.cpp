#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0715.cpp
//
//Author: dezhonger - csdisassembly@gmail.com

//Create: 2021-04-18 13:45:27

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


typedef pair<int, int> PII;
const int INF = 2e9;

#define x first
#define y second

class RangeModule {
    public:
        set<PII> s;
        RangeModule() {
            s.clear();
            s.insert({-INF, -INF});
            s.insert({INF, INF});
        }

        void addRange(int left, int right) {
            //找到第一个大于left的位置
            auto i = s.lower_bound({left, -INF});
            i--;//<=left的位置
            if (i -> y < left) {
                //这个区间和left没有交集
                i++;
            }
            if (i -> x > right) {
                //[left, right) 和当前区间没有交集
                s.insert({left, right});
            } else {
                //在右边找到一个和right有交集的区间
                auto j = i;
                while (j -> x <= right) j++;
                j--;
                PII t(min(i -> x, left), max(j -> y, right));
                while (i != j) {
                    auto k = i;
                    k++;
                    s.erase(i);
                    i = k;
                }
                s.erase(i);
                s.insert(t);
            }
            debug(s);
        }


        bool queryRange(int left, int right) {
            //找到第一个 > left的区间，因为有可能left有相等的，因此把second置为INF
            auto i = s.upper_bound({left, INF});
            i--;
            //i--后，找到的就是第一个 >= left的区间
            return (i -> y >= right);
        }

        void removeRange(int left, int right) {
            //找到第一个大于left的位置
            auto i = s.lower_bound({left, -INF});
            i--;//<=left的位置
            if (i -> y < left) {
                //这个区间和left没有交集
                i++;
            }
            if (i -> x > right) {
                //[left, right) 和当前区间没有交集
                debug(s);
                return ;
            } else {
                //在右边找到一个和right有交集的区间
                auto j = i;
                while (j -> x <= right) j++;
                j--;
                //删除区间后，计算出留下的部分。 
                auto t1 = get(*i, left, right);
                auto t2 = get(*j, left, right);
                while (i != j) {
                    auto k = i;
                    k++;
                    s.erase(i);
                    i = k;
                }
                s.erase(i);
                for (auto t : t1) s.insert(t);
                for (auto t : t2) s.insert(t);
            }
            debug(s);
        }
        vector<PII> get(PII a, int left, int right) {
            vector<PII> res;
            if (left >= a.y || right <= a.x) {
                res.push_back(a);
            }
            if (left <= a.x && right >= a.y) return res;
            if (a.x <= left && a.y >= right) {
                res.push_back({a.x, left});
                res.push_back({right, a.y});
            } else if (a.x <= left) {
                res.push_back({a.x, left});
            } else if (right < a.y) {
                res.push_back({right, a.y});
            }

            return res;
        }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right); * bool param_2 = obj->queryRange(left,right); * obj->removeRange(left,right);
 */

void f() {
    RangeModule* obj = new RangeModule();
    obj -> addRange(5, 8);
    cout << obj -> queryRange(3, 4) << endl;
    obj -> removeRange(5, 6);
    obj -> removeRange(3, 6);
    obj -> addRange(1, 3);
    cout << obj -> queryRange(2, 3) << endl;
    obj -> addRange(4, 8);
    cout << obj -> queryRange(2, 3) << endl;
    obj -> removeRange(4, 8);
}

void g() {
    RangeModule* obj = new RangeModule();
    obj -> removeRange(4, 8);
    obj -> addRange(1,10);
    obj -> queryRange(1, 7);
    obj -> addRange(2,3);
    obj -> removeRange(2, 3);
    obj -> queryRange(8, 9);
    obj -> queryRange(6, 9);
    obj -> addRange(2,3);
    return ;
}

int main() {
    ios::sync_with_stdio (false);
    cin.tie (0);
    g();
    return 0;
}

