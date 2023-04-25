class SmallestInfiniteSet {
public:
    int top=1;
    priority_queue<int,vector<int>,greater<int>> p;
    map<int,int> m;
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if(!p.empty() and p.top()<top) {
            int num=p.top();
            p.pop();
            m.erase(num);
            return num;
        }
        return top++;
    }
    
    void addBack(int num) {
        if(top>num and !m.count(num)){
            p.push(num);
            m[num]++;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */