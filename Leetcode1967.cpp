
const int N = 50050;
queue<int> q;
struct Aho_Corasick_Automaton{
    int c[N][26],val[N],fail[N],cnt;
    void init() {
        cnt = 0;
        memset(c, 0, sizeof c);
        memset(val, 0, sizeof val);
        memset(fail, 0, sizeof fail);
    }
    void ins(string& s){
        int len=s.size();int now=0;
        for(int i=0;i<len;i++){
            int v=s[i]-'a';
            if(!c[now][v])c[now][v]=++cnt;
            now=c[now][v];
        }
        val[now]++;
    }
    void build(){
        for(int i=0;i<26;i++)if(c[0][i])fail[c[0][i]]=0,q.push(c[0][i]);
        while(!q.empty()){
            int u=q.front();q.pop();
            for(int i=0;i<26;i++)
            if(c[u][i])fail[c[u][i]]=c[fail[u]][i],q.push(c[u][i]);
            else c[u][i]=c[fail[u]][i];
        }
    }
    int query(string& s){
        int len=s.size();int now=0,ans=0;
        for(int i=0;i<len;i++){
            now=c[now][s[i]-'a'];
            for(int t=now;t&&~val[t];t=fail[t])ans+=val[t],val[t]=-1;
        }
        return ans;
    }
}AC;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string p) {
        AC.init();
        for (string& p: patterns) AC.ins(p);
        AC.build();
        return AC.query(p);
    }
};
