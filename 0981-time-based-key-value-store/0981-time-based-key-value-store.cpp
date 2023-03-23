class TimeMap {
public:
    map<string,map<int,string>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].insert({-timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto it=m[key].lower_bound(-timestamp);
        if(it==m[key].end()) return "";
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */