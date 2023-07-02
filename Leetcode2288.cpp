class Solution {
public:
    string discountPrices(string sentence, int discount) {
        string res;
        istringstream iss(sentence);
        string t;
        while (getline(iss, t, ' ')) { // while (iss >> t)
            bool isPrice = (t.size() > 1 && t[0] == '$');
            if (isPrice) {
                for (int i = 1; i < t.size(); ++i) {
                    if (t[i] == '$' || t[i] < '0' || t[i] > '9') {
                        isPrice = 0; break;
                    }
                }
            }
            if (isPrice) {
                string p = t.substr(1);
                double price = stod(p);
                price *= (100 - discount) * 0.01;
                
                ostringstream oss;
                oss << fixed << setprecision(2) << price;
                
                res += '$' + oss.str() + ' ';
            } else {
                res += t + ' ';
            }
        }
        res.pop_back();
        return res;
    }
};
