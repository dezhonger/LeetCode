class BrowserHistory {
public:
    vector<string> urls;
    //c = current
    int l, r, c;
    BrowserHistory(string homepage) {
        urls = {homepage};
        //[l, r] 有效区间
        l = r = c = 0;
    }
    
    void visit(string url) {
        r = ++c;
        if (c < urls.size()) urls[c] = url;
        else urls.push_back(url);

    }
    
    string back(int steps) {
        int d = max(0, c - steps);
        c = d;
        return urls[d];
    }
    
    string forward(int steps) {
        int d = min(c + steps, r);
        c = d;
        return urls[d];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
