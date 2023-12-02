class RecentCounter {
public:
    vector<int> v;
    RecentCounter() {
        
    }
    
    int ping(int t) {
        int id=lower_bound(v.begin(),v.end(),t-3000)-v.begin();
        if(id<0) id=0;
        int ans = v.size()-id+1;
        v.push_back(t);
        return ans;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */