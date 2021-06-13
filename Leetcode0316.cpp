#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
using namespace std;

string removeDuplicateLetters(string s) {
    string ans;
    vector<char> v;
    map<char, int> m;
    vector<int> isHave(26, 0);
    v.push_back(0);
    for(unsigned int i = 0; i < s.size(); i++) {
        m[s[i]]++;
    }
    for(unsigned int i = 0; i < s.size(); i++) {
        if(isHave[s[i] - 'a'] == 0) {
            while(s[i] < *(v.end() - 1) && m[*(v.end() - 1)] > 0) {
                isHave[*(v.end() - 1) - 'a'] = 0;
                v.pop_back();
            }
            v.push_back(s[i]);
            isHave[s[i] - 'a'] = 1;
            m[s[i]]--;
        }
        else m[s[i]]--;


    }
    for(unsigned int i = 1; i < v.size(); i++) ans += v[i];
    return ans;
}

int main()
{
    string s = "bbcaac";
    cout << removeDuplicateLetters(s);
    return 0;
}
