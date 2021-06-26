typedef long long LL;
const int NN = 10000, N = 10005, M = 5;
int mod = (int)1e9 + 7;

class MovieRentingSystem {
public:

    set<pair<int, int>> st[N];
    set<pair<int, pair<int, int>>> jiechu;
    unordered_map<int, unordered_map<int, int>> mp;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (int i = 0; i <= NN; i++) st[i].clear();
        jiechu.clear();
        mp.clear();
        for (auto &e: entries) {
            int movie = e[1];
            int shop = e[0];
            int price = e[2];
            st[movie].insert({price, shop});
            mp[shop][movie] = price;
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        for (auto x: st[movie]) {
            res.push_back(x.second);
            if (res.size() >= M) break;
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        int price = mp[shop][movie];
        st[movie].erase({price, shop});
        pair<int, pair<int, int>> p = make_pair(price, make_pair(shop, movie));
        jiechu.insert(p);
    }
    
    void drop(int shop, int movie) {
        int price = mp[shop][movie];
        pair<int, pair<int, int>> p = make_pair(price, make_pair(shop, movie));
        jiechu.erase(p);
        st[movie].insert({price, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        for (auto& x: jiechu) {
            res.push_back({x.second.first, x.second.second});
            if (res.size() >= M) break;
        }
        return res;
    }
};
