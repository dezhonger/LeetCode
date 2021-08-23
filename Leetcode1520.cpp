struct Seg {
    int l, r;
    bool operator<(const Seg& other) const {
        if (r != other.r) return r < other.r;
        return other.l < l;
    }
};

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> c(26), l(26, -1), r(26, -1);
        int n = s.size();
        vector<string> res;
        for (int i = 0; i < n; i++) {
            c[s[i] - 'a']++;
            if (l[s[i] - 'a'] == -1) l[s[i] - 'a'] = i;
            r[s[i] - 'a'] = i;
        }
        vector<Seg> ss;
        for (int i = 0; i < 26; i++) {
            if (l[i] != -1) {
                Seg sg{l[i], r[i]};
                int f = 1;
                for (int j = sg.l; j <= sg.r; j++) {
                    int alpha = s[j] - 'a';
                    if (l[alpha] < l[i]) {f = 0; break;}
                    if (r[alpha] > sg.r) sg.r = r[alpha];
                }
                if (f) ss.push_back(sg);
            }
        }
        sort(ss.begin(), ss.end());
        int end = -1;
        for (int i = 0; i < ss.size(); i++) {
            if (ss[i].l >= end) {
                end = ss[i].r;
                //cout << ss[i].l << " " << ss[i].r << endl;
                res.push_back(s.substr(ss[i].l, ss[i].r - ss[i].l + 1));
            }
        }

        // xababx yycdcdyy
        // abcabc
        //xy a xb
        return res;
    }
};
