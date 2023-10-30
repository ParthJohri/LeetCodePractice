class RandomizedSet {
public:
    unordered_map<int,int> m;
    vector<int> pos;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.count(val)) return false;
        pos.push_back(val);
        m[val]=pos.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!m.count(val)) return false;
        int last_element=pos.back();
        // swap last element with the delete element
        m[last_element]=m[val];
        pos[m[val]]=last_element;
        
        // 1 3 5 7 9
        // We delete 5 and last is 9
        // 1 3 9 7 5 (we swap the deleted element with the last element)
        // 1 3 9 7 (Deletion done)
        // Now new index of 9 =.index of 5 (m[last_element]=m[val])
        
        pos.pop_back();
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        return pos[rand()%pos.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */