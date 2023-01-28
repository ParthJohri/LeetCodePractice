class SummaryRanges {
public:
    map<int,int> m;
    SummaryRanges() {
        m.clear();
    }
    
    void addNum(int value) {
        int left=value,right=value;
        auto justGreater=m.upper_bound(value);
        
        if(m.begin()!=justGreater){
            auto justLesser=justGreater;
            justLesser--;  
            if(justLesser->second>=value) return; // [1,4],[5,10] value 3
            if(justLesser->second==value-1){
                left=justLesser->first;
            }
        }
        if(m.end()!=justGreater and justGreater->first==value+1){
            right=justGreater->second;
            m.erase(justGreater);
        }
        m[left]=right;
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for(auto i:m){
            ans.push_back({i.first,i.second});
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */