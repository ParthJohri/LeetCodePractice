class LRUCache {
public:
    list<int> dll;
    map<int,pair<list<int>:: iterator,int>> m;
    int n;
    LRUCache(int capacity) {
        n=capacity;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){
            dll.erase(m[key].first);
            dll.push_front(key);
            m[key].first=dll.begin();
            return m[key].second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            m[key].second=value;
            dll.erase(m[key].first);
            dll.push_front(key);
            m[key].first=dll.begin();
        }
        else{
            dll.push_front(key);
            m[key]={dll.begin(),value};
            n--;
        }
        if(n<0){
            m.erase(dll.back());
            dll.pop_back();
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */