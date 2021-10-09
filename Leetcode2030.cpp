class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        // 需要删除的字符的数量
        int del = s.size() - k;
        // 当前串中letter字母的数量
        int cnt = 0;
        for (char c: s) {
            if (c == letter) cnt++;
        }
        
        vector<char> stk;
        for (char c: s) {
            while (del && !stk.empty()) {
                if (c < stk.back()) {
                    if (stk.back() != letter) {
                        stk.pop_back();
                        del--;
                    } else {
                        if (cnt > repetition) {
                            stk.pop_back();
                            del--;
                            cnt--;
                        } else {
                            break;
                        }
                    }
                } else {
                    break;
                }
            }
            stk.push_back(c);
        }
        
        string ans;
        for (int i = stk.size() - 1; i >= 0; i--) {
            if (del) {
                if (stk[i] != letter) del--;
                else {
                    if (cnt > repetition) {
                        cnt--;
                        del--;
                    } else {
                        ans.push_back(stk[i]);
                    }
                }
            } else {
                ans.push_back(stk[i]);
            }
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};

