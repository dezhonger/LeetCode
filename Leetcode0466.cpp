#include <bits/stdc++.h>
using namespace std;
//Filename: Leetcode0466.cpp
//代码有注释，可以和https://leetcode-cn.com/problems/count-the-repetitions/solution/tong-ji-zhong-fu-ge-shu-by-leetcode-solution/中的例子一起食用
//Author: dezhonger - csdisassembly@gmail.com
//Create: 2021-05-07 00:34:40
//Last modified: 2021-05-07 00:57:31

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


class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        vector<int> cnt;
        unordered_map<int, int> h;
        int l1 = s1.size(), l2 = s2.size();
        for (int i = 0, k = 0; i < n1; i++) {
            for (int j = 0; j < l1; j++) {
                if (s1[j] == s2[k % l2]) k++;
            }
            //记录第i个s1串结束后匹配的s2的字符个数
            cnt.push_back(k);
            debug(i, cnt);

            if (h.count(k % l2)) {
                //出现了循环节
                int last = h[k % l2];
                //循环节长度
                int period = i - last;
                //一个循环节内匹配的s2的字符数量
                int s2s = k - cnt[last];
                debug(period, s2s);

                //计算从i开始后还有多少个完整的循环节
                int cc = (n1 - (i + 1)) / period; //因为i是从0计数的，所以要加1
                //这么多个循环节内匹配了多少个s2的字符
                int res = cc * s2s;
                debug(cc, res);

                //最后可能还余下几个s1，暴力计算
                for (int u = 0; u < (n1 - (i + 1)) % period; u++) {
                    for (int v = 0; v < l1; v++) {
                        //这里的k是接上循环节之前的计算的，循环节内的已经提前计算到res内了。
                        if (s1[v] == s2[k % l2]) k++;
                    }
                }
                res += k;
                return res / l2 / n2;
            }
            h[k % l2] = i;
        }

        //没有出现过循环节
        return cnt.back() / l2 / n2;
    }
};


int main() {
    Solution s;
    cout << s.getMaxRepetitions("abaacdbac", 100, "adcbd", 4) << endl;
    return 0;
}

