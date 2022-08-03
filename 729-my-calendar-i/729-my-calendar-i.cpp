class MyCalendar {
public:
    vector<pair<int,int>> v;
    MyCalendar() {
        vector<pair<int,int>> ans;
        v=ans;
    }
    
    bool book(int start, int end) {
        for(auto i:v){
            if(!(start>=i.second || end<=i.first)){
                return false;
            }
        }
        v.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */