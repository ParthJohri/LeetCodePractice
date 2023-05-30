class MyHashSet {
public:
    list<int> k;
    MyHashSet() {
        list<int> m;
        k=m;
    }
    
    void add(int key) {
        k.push_back(key);
    }
    
    void remove(int key) {


            k.remove(key);
    }
    
    bool contains(int key) {
             for(auto it=k.begin();it!=k.end();it++)
            {
            if(*(it)==key)
                {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */