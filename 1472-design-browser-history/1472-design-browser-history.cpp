class BrowserHistory {
public:
    list<string> l,b,f;
    BrowserHistory(string homepage) {
       l.push_back(homepage); 
    }
    
    void visit(string url) {
        b.push_back(l.back());
        l.pop_back();
        f.clear();
        l.push_back(url);
    }
    
    string back(int steps) {
        while(steps-- && !b.empty()){
            f.push_back(l.back());
            l.pop_back();
            l.push_back(b.back());
            b.pop_back();
        }
        return l.back();
    }
    
    string forward(int steps) {
        while(steps-- && !f.empty()){
            b.push_back(l.back());
            l.pop_back();
            l.push_back(f.back());
            f.pop_back();
        }
        return l.back();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */