class RandomizedCollection {
public:
    unordered_map<int,unordered_set<int>> m;
    vector<int>pos;
    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        pos.push_back(val);
        m[val].insert(pos.size()-1);
        return m[val].size()==1;
    }
    
    bool remove(int val) {
        auto it=m.find(val);
        if(it!=m.end()){
            int deletingPos = *(it->second.begin());
            it->second.erase(it->second.begin());
            int lastElement = pos.back();
            pos[deletingPos]=lastElement;
            m[lastElement].insert(deletingPos);
            m[lastElement].erase(pos.size()-1);
            pos.pop_back();
            if(it->second.size()==0) m.erase(it);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return pos[rand()%pos.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */