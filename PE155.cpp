#include <bits/stdc++.h>
using namespace std;

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

// __builtin_popcount

typedef long long LL;

//https://oeis.org/A153588/list

const int N = 18;
//The better way to do is use fraction to strorge.
const double eps = 0.000001;
vector<set<long double>> v(N + 1);
vector<int> ans(N + 1);
set<long double> st;
void solve() {
    v[1] = {60};
    ans[1] = 1;
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= N / 2 ; j++) {
            for (auto x: v[j]) {
                for (auto y : v[i - j]) {
                    long double z1 = x + y;
                    long double z2 =  1.0*(x*y)/(x+y);
                    v[i].insert(z1);
                    v[i].insert(z2);
                }
            }
        }
        set<long double> tmp;
        double last = -1;
        for (auto x : v[i]) {
            if (fabs(x - last) > eps) tmp.insert(x);
            last = x;
        }
        v[i] = tmp;
        
    }
    for (int i = 1; i <= N; i++) {
        for (auto x: v[i]) st.insert(x);
    }
    
    double last = -1;
    int count = 0;
    for (auto x : st) {
        if (fabs(x - last) > eps) count++;
        last = x;
    }
    cout << "ans: " << count << endl;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto start = std::chrono::system_clock::now();
    solve();

    auto end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << elapsed.count() <<"ms" << '\n';
    //34.9s
    return 0;
}

