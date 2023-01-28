class SummaryRanges {
public:
    
    unordered_set<int> s;
    
    SummaryRanges() {
        s.clear();
    }
    
    void addNum(int value) {
        s.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        vector<int> v(s.begin(),s.end());
        
        sort(v.begin(),v.end());
        
        int i=0,n=v.size();
        for(int i=0;i<n;i++){
            int left=v[i];
            while(i<n-1 and v[i]+1==v[i+1]){
                i++;
            }
            ans.push_back({left,v[i]});
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