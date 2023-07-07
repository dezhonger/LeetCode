class FoodRatings {
    unordered_map<string, pair<int, string>> fs;
    unordered_map<string, set<pair<int, string>>> cs;
public:
    FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings) {
        for (int i = 0; i < foods.size(); ++i) {
            auto &f = foods[i], &c = cuisines[i];
            int r = ratings[i];
            fs[f] = {r, c};
            cs[c].emplace(-r, f);
        }
    }

    void changeRating(string food, int newRating) {
        auto &[r, c] = fs[food];
        auto &s = cs[c];
        s.erase({-r, food}); // 移除旧数据
        s.emplace(-newRating, food); // 添加新数据
        r = newRating;
    }

    string highestRated(string cuisine) {
        return cs[cuisine].begin()->second;
    }
};
